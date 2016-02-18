#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, K, X, T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d %d %d", &N, &K, &X);

        long long int x = 0;
        for(int i = 1; i <= N; i++)
        {
            x += i;
        }
        for(int i = X; i < X+K; i++)
        {
            x -= i;
        }

        printf("Case %d: %lld\n",t,x);
    }

}
