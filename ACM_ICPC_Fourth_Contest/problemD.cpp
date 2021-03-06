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
    long long A, B;
    char Sin[5000];
    bool S[5000];

    while(scanf("%lld %lld",&A, &B)!=EOF)
    {
        scanf("%s",&Sin);

        long long n = 0, p = 0;

        for(int i = 0; Sin[i]!='\0'; i++)
        {
            if(Sin[i]=='B')
            {
                S[i] = true;
                p++;
            }
            else S[i] = false;

            n++;
        }

        long long minCost = 0;
        long long numToMove = 0;
        for(int i = p; i < n; i++)
        {
            if(S[i]) numToMove++;
        }
        minCost = numToMove*A;
        long long swapCost = A-B;
        long long swappingCost = 0;

        long long curr = p;
        for(int i = 1; i <= numToMove; i++)
        {
            while(!S[curr]) curr++;
            
            for(int j = curr; j >= p; j--)
            {
                int k;
                for(k = j; S[k]; k--);

                S[j] = false;
                S[k] = true;
                swappingCost += (j-k)*swapCost;
            }

            minCost = min(minCost,swappingCost+(numToMove-i)*A);
        }
        printf("%lld\n",minCost);
    }

}
