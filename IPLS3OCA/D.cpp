#include <stdio.h>
using namespace std;

#define MOD 1000000007
typedef long long LL;

LL dp[100010];
LL sums[100010];
int main() {
    int t,k;
    scanf("%d %d", &t, &k);

    for (int i = 0; i < k; i++) {
        dp[i] = 1;
    }
    for (int i = k; i < 100010; i++) {
        dp[i] = (dp[i-1]+dp[i-k]) % MOD;
    }

    sums[0] = dp[0];
    for (int i = 0; i < 100010; i++) {
        sums[i] = (dp[i] + sums[i-1])%MOD;
    }

    /*
    for (int i = 0; i < 10; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
    */

    for (int test = 0; test < t; test++) {
        int a,b;
        scanf("%d %d", &a, &b);

        printf("%lld\n", (sums[b]-sums[a-1]+MOD)%MOD);
    }
    return 0;
}
