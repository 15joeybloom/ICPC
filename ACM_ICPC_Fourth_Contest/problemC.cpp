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
    long long int choose2[1002];
    choose2[0] = 0;
    choose2[1] = 0;
    choose2[2] = 1;
    for(int i = 3; i < 1002; i++)
    {
        choose2[i] = choose2[i-1]+i-1;
    }

    int sum[2002],diff[2002];
    for(int i = 0; i < 2002; i++)
    {
        sum[i] = 0;
        diff[i] = 0;
    }

    int n, x, y;

    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&x,&y);

        sum[x+y]++;
        diff[x-y+1000]++;
    }

    long long int pairs = 0;
    for(int i = 0; i < 2002; i++)
    {
        pairs += choose2[sum[i]];
        pairs += choose2[diff[i]];
    }

    printf("%lld\n",pairs);

}
