#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <limits>
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

LL n;
LL coins[110];
LL greedy(LL x) {
    LL y = 0;
    for (int i = n-1; i >= 0; i--) {
        y += x / coins[i];
        x %= coins[i];
    }
    return y;
}

LL dp[2000010];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    LL N = coins[n-1]+coins[n-2];
    //LL infinity = 10000000000LL;
    LL infinity = n*N;
    for (int i = 0; i < N; i++)
        dp[i] = infinity;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        LL c = coins[i];
        for (LL j = c; j < N; j++)
            dp[j] = min(dp[j],dp[j-c]+1);
    }

    /*
    for (int i = 0; i < N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    */

    for (int i = 0; i < N; i++)
        if (greedy(i) != dp[i]) {
            /*
            cout << "counterexample is " << i << endl;
            cout << "greedy is " << greedy(i) << endl;
            cout << "dp is " << dp[i] << endl;
            */
            cout << "non-canonical" << endl;
            return 0;
        }

    cout << "canonical" << endl;
    return 0;
}
