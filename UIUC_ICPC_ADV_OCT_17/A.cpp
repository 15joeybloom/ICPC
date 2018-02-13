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
bool isPrime[1010];
vector<LL> primes;

int main()
{
    memset(isPrime, 0xFF, sizeof(isPrime));
    primes.push_back(1);
    for(int i = 2; i <= 1000; i++)
    {
        if(isPrime[i])
        {
            for(int j = 2*i; j <= 1000; j += i)
                isPrime[j] = false;

            primes.push_back(i);
            //printf("%lld\n", primes.back());
        }
    }
    LL N, C;
    while(scanf("%lld %lld", &N, &C) != EOF)
    {
        int left = 0, right = primes.size();
        while(left + 1 < right)
        {
            int middle = (left+right)>>1;
            if(primes[middle] < N)
                left = middle;
            else
                right = middle;
        }
        int numPrimes = left + 1;
        if(isPrime[N]) numPrimes++;

        printf("%lld %lld:", N, C);
        if(N == 1)
        {
            printf(" 1");
        }
        else if(2*C >= numPrimes)
        {
            for(int i = 0; i < numPrimes; i++)
                printf(" %lld", primes[i]);
        }
        else if(numPrimes & 1)
        {
            int bottomIndex = ((numPrimes>>1)-C)+1;
            for(int i = 0; i < 2*C-1; i++)
            {
                printf(" %lld", primes[bottomIndex+i]);
            }
        }
        else
        {
            int bottomIndex = ((numPrimes+1)>>1)-C;
            for(int i = 0; i < 2*C; i++)
            {
                printf(" %lld", primes[bottomIndex+i]);
            }
        }
        printf("\n\n");
    }
}
