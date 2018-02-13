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
typedef pair<LL,LL> PLL;

vector<PLL> adj[1010];
LL t[1010];
LL c[1010];
LL dp[1010];
bool marked1[1010];
bool marked2[1010];
LL infinity = LLONG_MAX;
int main()
{
    LL n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;

    for (int i = 0; i < m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> c[i];
    }

    for (int i = 0; i < n; i++) dp[i] = infinity;
    dp[x] = 0;
    memset(marked1, false, sizeof(marked1));
    vector<LL> stk1;
    stk1.push_back(x);
    while(!stk1.empty()) {
        LL u1 = stk1.back();
        stk1.pop_back();
        if (marked1[u1])
            continue;
        marked1[u1] = true;

        memset(marked2, false, sizeof(marked2));
        vector<PLL> stk2;
        stk2.push_back(make_pair(u1,0));
        while(!stk2.empty()) {
            PLL p2 = stk2.back();
            LL u2 = p2.first;
            LL d = p2.second;
            stk2.pop_back();
            if(marked2[u2])
                continue;
            marked2[u2] = true;

            dp[u2] = min(dp[u2], dp[u1]+c[u1]);
            for (PLL edge : adj[u2]) {
                LL v2 = edge.first;
                LL w = edge.second;
                if (!marked2[v2] && w+d <= t[u1])
                    stk2.push_back(make_pair(v2,w+d));
            }
        }

        for (auto edge : adj[u1]) {
            LL v1 = edge.first;
            LL w = edge.second;
            if (!marked1[v1])
                stk1.push_back(v1);
        }
    }

    if (dp[y] == infinity)
        cout << -1 << endl;
    else
        cout << dp[y] << endl;
}
