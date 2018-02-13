#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>
using namespace std;

typedef long long LL;

LL dp[20][20];
LL dims[20];
int N;

LL range(int a, int b)
{
    if(dp[a][b] > 0)
        return dp[a][b];
    if(b-a==2)
        return dims[a]*dims[a+1]*dims[b];

}
int main()
{
    while(true)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &N);
        if(N == 0)
            return 0;

        for(int i = 0; i < N; i++)
        {
            LL r, c;
            scanf("%lld %lld", &r, &c);
            dims[i]= r;
            dims[i+1] = c;
        }
    }
}
