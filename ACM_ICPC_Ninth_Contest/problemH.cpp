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
    int k, n;

    double dp[101][10];

    for(int i = 0; i < 10; i++)
    {
        dp[0][i] = 1.0;
    }
    while(scanf("%d %d", &k, &n)!=EOF)
    {
        k++;
        if(k < 3)
        {
            printf("100.00000\n");
            continue;
        }

        double outof = k;
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i-1][0]+dp[i-1][1];
            for(int j = 1; j < k-1 ; j++)
            {
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
            }
            dp[i][k-1] = dp[i-1][k-2]+dp[i-1][k-1];

            outof *= k;
        }
        double sum = 0.0;
        for(int j = 0; j < k; j++)
            sum += dp[n-1][j];

        printf("%.5f\n", sum/outof*100);
    }
}
