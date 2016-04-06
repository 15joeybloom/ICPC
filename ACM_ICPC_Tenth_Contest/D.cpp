#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int l, n, c[55];

    long int A[55][55];

    while(scanf("%d", &l)!=EOF && l)
    {
        scanf("%d", &n);

        c[0] = 0;
        for(int i = 1 ; i <= n; i++)
        {
            scanf("%d", &c[i]);
        }
        c[n+1] = l;

        for(int i = 0; i <= n; i++)
        {
            A[i][i+1] = 0;
        }

        for(int i = 2; i <= n+1; i++)
        {
            for(int j = 0; j <= n+1-i; j++)
            {
                A[j][j+i] = LONG_MAX;
                for(int k = j+1; k < j+i; k++)
                    A[j][j+i] = min(A[j][j+i], A[j][k]+A[k][j+i]+c[j+i]-c[j]);
            }
        }

        printf("The minimum cutting is %d.\n", A[0][n+1]);
    }
}
