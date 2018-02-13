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
#include <functional>
using namespace std;

typedef long long LL;
#define MAXN 100010
int n, m, s;

typedef pair<LL,int> PLLI;
vector<PLLI> adj[MAXN];
LL dist[MAXN];
bool visited[MAXN];
priority_queue<PLLI,vector<PLLI>,greater<PLLI> > pq;
int main()
{
    cin >> n >> m >> s;
    s--;

    for (int i = 0; i < m; i++) {
        int v, u;
        LL w;
        cin >> v >> u >> w;
        v--;
        u--;
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    LL l;
    cin >> l;

    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));

    pq.push(make_pair(0,s));
    while (!pq.empty()) {
        PLLI p = pq.top();
        pq.pop();
        LL d = p.first;
        int i = p.second;
        if (d > l)
            break;
        if (!visited[i]) {
            visited[i] = true;
            dist[i] = d;
            for (PLLI q : adj[i])
                pq.push(make_pair(d+q.first,q.second));
        }
    }

    int counter = 0;
    for (int i = 0; i < n; i++)
        if (dist[i] == l)
            counter++;
    for (int i = 0; i < n; i++)
        for (PLLI p : adj[i]) {
            int j = p.second;
            if (i > j)
                continue;
            LL w = p.first;

            if (dist[i] < l && dist[i] + w > l && dist[j] + dist[i] + w - l >= l)
                counter++;
            if (dist[j] < l && dist[j] + w > l && dist[i] + dist[j] + w - l > l)
                counter++;
            continue;
            if (dist[i] < l && l - dist[i] < w && w - (l - dist[i]) + dist[j] > l)
                counter++;
            if (dist[j] < l && l - dist[j] < w && w - (l - dist[j]) + dist[i] > l)
                counter++;
            if (dist[j] < l && dist[i] < l && dist[i] + dist[j] + w == 2 * l)
                counter++;
        }
    cout << counter << endl;
}
