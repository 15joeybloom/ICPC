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
typedef pair<LL, int> P;
LL n, m, d, a[200010];
P sorted[200010];
int day[200010];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    scanf("%lld %lld %lld", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        sorted[i] = {a[i], i};
    }
    sort(sorted, sorted+n);
    int j = 0;
    int worst = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && sorted[i].first + d >= sorted[j].first)
            j++;
        worst = max(worst, j-i);
    }
    for (int i = 0; i < n; i++) {
        day[sorted[i].second] = i % worst + 1;
    }
    printf("%d\n", worst);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", day[i]);
    }
    printf("%d\n", day[n-1]);
}
