#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;

#define MOD 0x7FFFFFFF

typedef long long LL;
typedef pair<int, int> pii;

LL DP[1010][1010];
char input[1010][1010];
int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%s", input[i]+1);

    memset(DP, 0, sizeof(DP));

    DP[0][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(input[i][j] == '.')
            {
                DP[i][j] = (DP[i-1][j]+DP[i][j-1])%MOD;
            }
        }

    if(DP[n][n] > 0)
    {
        printf("%lld\n", DP[n][n]);
        return 0;
    }

    queue<pii> bfs;
    memset(DP, -1, sizeof(DP));
    bfs.push(make_pair(1,1));
    while(!bfs.empty())
    {
        pii p = bfs.front();
        bfs.pop();

        if(input[p.first][p.second] == '#')
            continue;

        if(p.first == n && p.second == n)
        {
            printf("THE GAME IS A LIE\n");
            return 0;
        }


        int dist =1;
        if(1 <= p.first + dist && p.first + dist<= n
            && 1 <= p.second && p.second <= n
            && DP[p.first + dist][p.second] == -1)
        {
            bfs.push(make_pair(p.first+dist, p.second));
            DP[p.first+dist][p.second] = 0;
        }
        if(1 <= p.first - dist && p.first - dist<= n
            && 1 <= p.second && p.second <= n
            && DP[p.first - dist][p.second] == -1)
        {
            bfs.push(make_pair(p.first-dist, p.second));
            DP[p.first-dist][p.second] = 0;
        }
        if(1 <= p.first && p.first <= n
            && 1 <= p.second + dist && p.second + dist <= n
            && DP[p.first][p.second+ dist ] == -1)
        {
            bfs.push(make_pair(p.first, p.second+ dist) );
            DP[p.first][p.second+ dist ] =0;
        }
        if(1 <= p.first && p.first <= n
            && 1 <= p.second - dist&& p.second - dist<=n
            && DP[p.first][p.second- dist] == -1)
        {
            bfs.push(make_pair(p.first, p.second- dist));
            DP[p.first][p.second- dist] = 0;
        }
    }

    printf("INCONCEIVABLE\n");
}
