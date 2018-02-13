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

#define MOD 1000000007
#define MAXN 5003

typedef long long LL;

LL choose[MAXN][MAXN+1];
int main()
{
    choose[1][0] = choose[1][1] = 1;
    for (int i = 0; i < MAXN; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = choose[i-1][j]+choose[i-1][j-1];
            choose[i][j] %= MOD;
        }
    }

    LL N,K;
    cin >> N >> K;
    while (N != 0) {
        if (K % 2 == 1) {
            LL m = (K+1)/2;
            //cout << "2 * choose[" << N-2 << "][" << m-1 << "]^2)" << endl;
            cout << (2*choose[N-2][m-1]*choose[N-2][m-1])%MOD << endl;
        } else {
            LL ma = K/2;
            LL mb = K/2+1;
            //cout << "2 * choose[" << N-2 << "][" << ma-1 << "]*choose[" << N-2 << "][" << mb-1 << "])" << endl;
            cout << (2*choose[N-2][ma-1]*choose[N-2][mb-1])%MOD << endl;
        }
        cin >> N >> K;
    }
}
