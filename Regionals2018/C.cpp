#include <bits/stdc++.h>
using namespace std;

#define INF 10000000000LL
typedef long long LL;

LL adj[4000][4000];
int n, m;
int bank, sink;
LL cost[400];
char terrain[40][40];
bool visited[4000];
int parent[4000];
LL answer;

LL getcap(int i, int j) {
    if (terrain[i][j] == '.' || terrain[i][j] == 'B')
        return INF;
    return cost[terrain[i][j]];
}
int index(int i, int j, bool in) {
    return 2*(i*n+j)+(in?1:0);
}
bool tryff() {
    memset(visited, 0, sizeof(visited));
    vector<int> stk;
    stk.push_back(bank);
    visited[bank] = true;
    while (!stk.empty()) {
        int curr = stk.back();
        stk.pop_back();
        if (curr == sink) {
            LL augment = INF;
            int x = curr;
            while (x != bank) {
                int y = parent[x];
                augment = min(augment, adj[y][x]);
                x = y;
            }
            x = curr;
            while (x != bank) {
                int y = parent[x];
                adj[y][x] -= augment;
                adj[x][y] += augment;
                x = y;
            }
            answer += augment;
            return true;
        }
        for (int next = 0; next <= sink; next++) {
            if (adj[curr][next] > 0 && !visited[next]) {
                parent[next] = curr;
                stk.push_back(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main()
{
    int let;
    scanf("%d %d %d", &n, &m, &let);
    for (int i = 0; i < m; i++) {
        scanf("%s\n", terrain[i]);
    }
    for (char c = 'a'; c < 'a'+let; c++) {
        scanf("%lld", cost+c);
    }

    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (terrain[i][j] == 'B')
                bank = index(i, j, true);
            adj[index(i,j,true)][index(i,j,false)] = getcap(i,j);
        }
    }
    sink = 2*n*m;

    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n; j++) {
            adj[index(i,j,false)][index(i+1,j,true)] = INF;
            adj[index(i+1,j,false)][index(i,j,true)] = INF;

        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n-1; j++) {
            adj[index(i,j,false)][index(i,j+1,true)] = INF;
            adj[index(i,j+1,false)][index(i,j,true)] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        adj[index(i,0,false)][sink] = INF;
        adj[index(i,n-1,false)][sink] = INF;
    }
    for (int i = 1; i < n-1; i++) {
        adj[index(0,i,false)][sink] = INF;
        adj[index(m-1,i,false)][sink] = INF;
    }

    memset(visited, 0, sizeof(visited));
    vector<int> stk;
    stk.push_back(bank);
    while (!stk.empty()) {
        int curr = stk.back();
        stk.pop_back();
        if (curr == sink) {
            printf("-1\n");
            return 0;
        }
        for (int next = 0; next <= sink; next++) {
            if (adj[curr][next] == INF && !visited[next]) {
                stk.push_back(next);
                visited[next] = true;
            }
        }
    }

    answer = 0;
    bool keep_going = true;
    while (keep_going)
        keep_going = tryff();
    printf("%lld\n", answer);
}
