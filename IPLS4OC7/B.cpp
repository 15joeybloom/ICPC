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

//bool isprime[1000010];

bool fnisprime(LL x) {
    for (int i = 2; i <= ceil(sqrt(x)); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    /*
    memset(isprime, -1, sizeof(isprime));
    for (int i = 2; i < sizeof(isprime); i++) {
        if (isprime[i]) {
            for (int j = 2*i; j < sizeof(isprime); j+=i)
                isprime[j] = false;
        }

    }
    */
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        LL a, b;
        scanf("%lld %lld", &a, &b);

        if (a+b != 1 && a-b != 1)
            printf("NO\n");
        else if (a-b == 1 && fnisprime(a+b))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
