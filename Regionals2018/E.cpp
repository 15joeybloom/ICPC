#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL mobius  [10000010];
bool isprime[10000010];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    LL a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    LL n = max(b, d);

    for (LL i = 1; i <= n; i++) {
        mobius[i] = 1;
        isprime[i] = true;
    }
    for (LL i = 2; i <= n; i++) {
        if (isprime[i]) {
            mobius[i] = -1;
            for (LL j = i+i; j <= n; j+=i) {
                isprime[j] = false;
                mobius[j] *= -1;
            }
            LL isq = i*i;
            for (LL j = isq; j <= n; j+=isq) {
                mobius[j] = 0;
            }
        }
    }

    LL answer = (b-a+1)*(d-c+1);
    for (LL i = 2; i <= n; i++) {
        answer += mobius[i] * ((b)/i-(a-1)/i) * (d/i-(c-1)/i);
    }
    printf("%lld\n", answer);
}
