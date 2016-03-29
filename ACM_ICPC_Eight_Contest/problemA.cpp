#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const long long int NUM_PRIMES = 1000034;
bool primes[NUM_PRIMES];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < NUM_PRIMES; i++)
        primes[i] = true;

    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= NUM_PRIMES; i++)
    {
        if(primes[i])
            for(long long int j = i+i; j < NUM_PRIMES; j+=i)
                primes[j] = false;
    }

    long long x;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &x);

        long long int mysqrt = round(sqrt(x));
        if(mysqrt*mysqrt!=x || !primes[mysqrt])
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }
}
