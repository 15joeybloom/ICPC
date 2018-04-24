#include<stdio.h>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

typedef long long LL;

struct Edge {
    LL u,v,d;
};

LL N,M,S,T,distS[100010],distT[100010],numS[100010],numT[100010];
vector<Edge> adj[100010];

int main() {
    for (int i = 0; i < 100010; i++) {
        distS[i] = distT[i] = LLONG_MAX;
        numS[i] = numT[i] = 0;
    }

    scanf("%lld %lld", &N, &M);
    scanf("%lld %lld", &S, &T);
    for (int i = 0; i < M; i++) {
        Edge e;
        scanf("%lld %lld %lld", &e.u, &e.v, &e.d);
        adj[e.u].push_back(e);
        adj[e.v].push_back(e);
    }


    auto cmp = [](Edge left, Edge right) { 
        return left.d > right.d;
    };
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> qS(cmp);
    for ( Edge e : adj[S] ) qS.push(e);
    distS[S] = 0;
    while (!qS.empty()) {
        Edge e = qS.top();
        qS.pop();

        if (distS[e.v] == LLONG_MAX) {
            for (Edge f : adj[e.v]) 
                if (distS[f.u] == LLONG_MAX || distS[f.v] == LLONG_MAX) qS.push(f);
            distS[e.v] = distS[e.u] + e.d;
        }
        else if (distS[e.u] == LLONG_MAX) {
            for (Edge f : adj[e.u]) 
                if (distS[f.u] == LLONG_MAX || distS[f.v] == LLONG_MAX) qS.push(f);
            distS[e.u] = distS[e.v] + e.d;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%lld ", distS[i]);
    }
    printf("\n");

    return 0;
}
