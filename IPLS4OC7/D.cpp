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

#define MOD 998244353
typedef long long LL;

LL dpsame[1010][2010], dpdiff[1010][2010];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    memset(dpsame, 0, sizeof(dpsame));
    memset(dpdiff, 0, sizeof(dpdiff));
    dpsame[1][1] = 2;
    dpsame[1][2] = 0;
    dpdiff[1][1] = 0;
    dpdiff[1][2] = 2;
    for (int i = 2; i <= n; i++) {
        dpsame[i][1] = 2;
        dpdiff[i][1] = 0;
        for (int j = 2; j <= 2*i; j++) {
            dpdiff[i][j] = 0;
            dpdiff[i][j] += 2*dpsame[i-1][j-1] % MOD;
            dpdiff[i][j] %= MOD;
            dpdiff[i][j] += dpdiff[i-1][j];
            dpdiff[i][j] %= MOD;
            dpdiff[i][j] += dpdiff[i-1][j-2];
            dpdiff[i][j] %= MOD;
            //dpsame[i][j] = 2*dpdiff[i-1][j] + dpsame[i-1][j] + dpsame[i-1][j-1];
            dpsame[i][j] = 0;
            dpsame[i][j] += 2*dpdiff[i-1][j] % MOD;
            dpsame[i][j] %= MOD;
            dpsame[i][j] += dpsame[i-1][j];
            dpsame[i][j] %= MOD;
            dpsame[i][j] += dpsame[i-1][j-1];
            dpsame[i][j] %= MOD;
        }
    }

    printf("%lld\n", (dpdiff[n][k] + dpsame[n][k]) % MOD);
}
