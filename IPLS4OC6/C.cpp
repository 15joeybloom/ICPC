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

LL gcd(LL x, LL y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

LL n, p, q, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &p, &q, &b);
        p %= q;
        q /= gcd(p, q);
        while (gcd(q, b) != 1)
            q /= gcd(q, b);
        if (q == 1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
}
