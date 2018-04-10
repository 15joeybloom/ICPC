#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;


bool visited[2010];
vector<LL> adj[2010];
double x[2010], y[2010], r[2010];
int main () {
    double H,W;
    LL N;
    cin >> H >> W >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    //cout << "Read input!" << endl;

    for (int i = 0; i < N; i++) {
        if (x[i]-r[i] < 0) {
            adj[i].push_back(N);
            adj[N].push_back(i);
        }
        //cout << "Left" << endl;
        if (x[i]+r[i] > W) {
            adj[i].push_back(N+1);
            adj[N+1].push_back(i);
        }
        //cout << "Right" << endl;
        for (int j = i + 1; j < N; j++) {
            double dx = x[i]-x[j];
            double dy = y[i]-y[j];
            double bigr = r[i]+r[j];
            if (dx*dx + dy*dy < bigr*bigr) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

            //cout << "Pairs!" << endl;
        }
    }

    //cout << "Built graph!" << endl;

    memset(visited, false, sizeof(visited));
    vector<LL> stk;
    stk.push_back(N);
    while (!stk.empty()) {
        LL curr = stk.back();
        stk.pop_back();

        if (!visited[curr]) {
            visited[curr] = true;
            for (LL next : adj[curr]) {
                stk.push_back(next);
            }
        }
    }

    if (visited[N+1]) {
        cout << "NO NO NO" << endl;
    } else {
        cout << "YES YES YES" << endl;
    }
}
