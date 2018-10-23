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
LL n, p, q, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &p, &q, &b);
        p %= q;
        set<LL> rems;
        bool finite = true;
        while (p != 0) {
            printf("%lld\n", p);
            if (rems.count(p) != 0) {
                finite = false;
                break;
            }
            rems.insert(p);
            p *= b;
            p %= q;
        }
        if (finite)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
}
