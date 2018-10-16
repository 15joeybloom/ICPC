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

LL l, a, b, t, r, n;
LL Dcool, Dcup;
LL carts[500010], next[500010], best[500010];
double dp[500010];
int main()
{
    scanf("%lld %lld %lld %lld %lld", &l, &a, &b, &t, &r);
    Dcool = a*t;
    Dcup = a*t+b*r;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", carts+i);
    carts[n] = l;

    LL ahead = 1;
    for (LL i = 0; i < n; i++) {
        while (ahead < n && carts[ahead] < carts[i] + Dcup)
            ahead++;
        next[i] = ahead;
    }

    dp[n] = 0;
    for (LL i = n-1; i >= 0; i--) {
        double one = (carts[i+1]-carts[i])/a + dp[i+1];
        double three = t + r + (carts[next[i]]-Dcup-carts[i])/(double)a + dp[next[i]];
        double two;
        if (next[i] != i+1)
            two = t + (carts[next[i]-1]-Dcool-carts[i])/(double)b + dp[next[i]-1];
        else
            two = three;
        printf("%lf %lf\n", two, three);
        dp[i] = min(min(one, two), three);
        if (dp[i] == three)
            best[i] = next[i];
        else if (dp[i] == one)
            best[i] = i+1;
        else
            best[i] = next[i]-1;
    }

    vector<LL> stops;
    stops.push_back(0);
    while (best[stops.back()] < n) {
        stops.push_back(best[stops.back()]);
    }
    printf("%lld\n0", stops.size());
    for (int i = 1; i < stops.size(); i++) {
        printf(" %lld", stops[i]);
    }
    printf("\n");
}
