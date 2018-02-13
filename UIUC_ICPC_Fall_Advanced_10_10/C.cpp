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

#define MOD 1000000000
int k;
void matmul(LL **res, LL **A, LL **B)
{
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
        {
            res[i][j] = 0;
            for(int m = 0; m < k; m++)
            {
                res[i][j] + (A[i][k] * B[k][j]) ;
                res[i][j] %= MOD;
            }
        }
}

int main()
{

    int C;
    scanf("%d", &C);
    for(int t = 1; t <= C; t++)
    {
        scanf("%d", &k);
        
        LL b[11];
        LL A[11][11];
        LL res1[11][11];
        LL res2[11][11];

        for(int i = 0; i < k; i++)
            scanf("%lld", b+i);
        for(int i = 0; i < k; i++)
            scanf("%lld", b[0]+i);

        for(int i = 1; i < k; i++)
            for(int j = 0; j < k; j++)
                res1[i][j] = A[i][j] = 0;
        for(int i = 1; i < k; i++)
            res1[i][i-1] = A[i][i-1] = 1;

        LL n;
        scanf("%lld", &n);

        if(n <= k)
        {
            printf("%lld\n", b[n-1]);
            continue;
        }


        while(n > 1)
        {
            if(n & 1)
            {
                matmul(res2, res1, A);
                n--;
            }
            else
            {
                matmul(res2, res1, res1);
                n/=2;
            }
            memcpy(res1, res2, sizeof(res2));
        }

        LL an = 0;
        for(int i = 0; i < k; i++)
            an += A[0][i] * b[i];
        printf("%lld\n", an);
    }
}
