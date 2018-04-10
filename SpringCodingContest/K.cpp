#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define INF 1000000000
typedef long long LL;

int N,M;
int adj[50][50], contracted[50][50];

int K,L;
int bonfires[50];

int solution = INF;

vector<int> kindled;
void picksubset(int k) {
    if (k == K && kindled.size() < L) return;
    if (k < K && kindled.size() < L) {
        kindled.push_back(k);
        picksubset(k+1);
        kindled.pop_back();
        picksubset(k+1);
        return;
    }

    /*
    for (int kin : kindled) {
        cout << kin << " ";
    }
    cout << endl;
    */

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            contracted[i][j] = adj[i][j];
        }
    }
    for (int i = 0; i < L; i++) {
        for (int j = i+1; j < L; j++) {
            contracted[kindled[i]][kindled[j]] = 0;
            contracted[kindled[j]][kindled[i]] = 0;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                contracted[i][j] = min(contracted[i][j],contracted[i][k]+contracted[k][j]);
            }
        }
    }

    int longest = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            longest = max(longest,contracted[i][j]);
        }
    }
    solution = min(longest, solution);
}

int main () {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = INF;
        }
        adj[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u][v] = adj[v][u] = min(adj[u][v],w);
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    cin >> K >> L;

    for (int i = 0; i < K; i++) {
        cin >> bonfires[i];
        bonfires[i]--;
    }

    picksubset(0);

    cout << solution << endl;
}
