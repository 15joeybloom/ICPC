#include<stdio.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007
typedef long long LL;

struct Edge {
    LL to,d;
};

LL N,M,S,T,distS[100010],distT[100010],numS[100010],numT[100010];
vector<Edge> adj[100010];
bool visited[100010];

struct cmp {
    bool reverse;
    LL *dist;
    cmp(LL* d, bool r) { dist = d; reverse = r; }
    bool operator()(LL left, LL right) {
        return reverse != (dist[left] < dist[right]);
    }
};
void dijkstra(LL *dist, LL source) {
    for (int i = 1; i <= N; i++) visited[i] = false;
    std::priority_queue<LL, std::vector<LL>, cmp> q(cmp(dist,true));
    q.push(source);
    dist[source] = 0;
    while (!q.empty()) {
        LL curr = q.top();
        q.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            for (Edge f : adj[curr]) {
                if (!visited[f.to] && dist[f.to] > dist[curr] + f.d) {
                    dist[f.to] = dist[curr] + f.d;
                    q.push(f.to);
                }
            }
        }
    }
    /*
    for (int i = 1; i <= N; i++) {
        printf("%lld ", dist[i]);
    }
    printf("\n");
    */
}

void countShortestPaths(LL *num, LL *dist, LL source) {
    vector<LL> vertices;
    for (int i = 1; i <= N; i++) vertices.push_back(i);
    sort(vertices.begin(), vertices.end(), cmp(dist,false));
    num[source] = 1;
    for (LL v : vertices) {
        for (Edge e : adj[v]) {
            if (dist[e.to] == dist[v] + e.d) {
                num[e.to] += num[v];
                num[e.to] %= MOD;
            }
        }
    }
    /*
    for (int i = 1; i <= N; i++) {
        printf("%lld ", num[i]);
    }
    printf("\n");
    */
}

int main() {
    for (int i = 0; i < 100010; i++) {
        distS[i] = distT[i] = LLONG_MAX/2;
        numS[i] = numT[i] = 0;
    }

    scanf("%lld %lld", &N, &M);
    scanf("%lld %lld", &S, &T);
    for (int i = 0; i < M; i++) {
        Edge e1,e2;
        scanf("%lld %lld %lld", &e1.to, &e2.to, &e1.d);
        e2.d = e1.d;
        adj[e1.to].push_back(e2);
        adj[e2.to].push_back(e1);
    }

    dijkstra(distS, S);
    dijkstra(distT, T);
    LL D = distS[T];

    countShortestPaths(numS, distS, S);
    countShortestPaths(numT, distT, T);

    LL answer = numS[T]*numS[T];
    answer %= MOD;
    for (int i = 1; i <= N; i++) {
        if (distS[i] == distT[i] && 2*distS[i] == D) {
            answer -= numS[i]*numS[i]*numT[i]*numT[i];
            if (answer < 0) answer += MOD * (-answer/MOD);
            while (answer < 0) answer += MOD;
            answer %= MOD;
        }
        for (Edge e : adj[i]) {
            if (2*distS[i] < D && 2*distT[e.to] < D && distS[i] + e.d + distT[e.to] == D) {
                answer -= numS[i]*numS[i]*numT[e.to]*numT[e.to];
                if (answer < 0) answer += MOD * (-answer/MOD);
                while (answer < 0) answer += MOD;
                answer %= MOD;
            }
        }
    }
    printf("%lld\n", answer);

    return 0;
}
