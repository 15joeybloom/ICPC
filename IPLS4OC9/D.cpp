#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, k, a[100010];
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x%y);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", a+i);

    int g = k;
    for (int i = 0; i < n; i++)
        g = gcd(g, a[i]);

    vector<int> results;
    for (int i = 0; i < k; i++) {
        if (i % g == 0)
            results.push_back(i);
    }
    printf("%d\n", results.size());
    if (results.size() > 0) {
        for (int i = 0; i < results.size() - 1; i++) 
            printf("%d ", results[i]);
        printf("%d\n", results.back());
    }
}
