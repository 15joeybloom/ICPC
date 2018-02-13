#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int mmmove[510][510];
int DP[510][510];
int main()
{
    memset(DP, -1, sizeof(DP));

    int n, m;
    scanf("%d %d\n", &n, &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char c;
            scanf("%c", &c);
            mmmove[i][j] = c-'0';
        }
        scanf("\n");
    }


    queue<pii> bfs;
    DP[0][0] = 0;
    bfs.push(make_pair(0,0));
    while(!bfs.empty())
    {
        pii p = bfs.front();
        bfs.pop();

        if(p.first == n-1 && p.second == m-1)
        {
            printf("%d\n", DP[n-1][m-1]);
            return 0;
        }

        int dist = mmmove[p.first][p.second];

        if(0 <= p.first + dist && p.first + dist< n
            && 0 <= p.second && p.second < m
            && DP[p.first + dist][p.second] == -1)
        {
            bfs.push(make_pair(p.first+dist, p.second));
            DP[p.first+dist][p.second] = DP[p.first][p.second]+1;
        }
        if(0 <= p.first - dist && p.first - dist< n
            && 0 <= p.second && p.second < m
            && DP[p.first - dist][p.second] == -1)
        {
            bfs.push(make_pair(p.first-dist, p.second));
            DP[p.first-dist][p.second] = DP[p.first][p.second]+1;
        }
        if(0 <= p.first && p.first < n
            && 0 <= p.second + dist && p.second + dist < m
            && DP[p.first][p.second+ dist ] == -1)
        {
            bfs.push(make_pair(p.first, p.second+ dist) );
            DP[p.first][p.second+ dist ] = DP[p.first][p.second]+1;
        }
        if(0 <= p.first && p.first < n
            && 0 <= p.second - dist&& p.second - dist< m
            && DP[p.first][p.second- dist] == -1)
        {
            bfs.push(make_pair(p.first, p.second- dist));
            DP[p.first][p.second- dist] = DP[p.first][p.second]+1;
        }
    }

    printf("-1\n");
}
