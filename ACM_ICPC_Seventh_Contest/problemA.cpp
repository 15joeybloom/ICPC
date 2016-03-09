#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool visited[10001];
vector<int> edges[10001];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    if(N != M+1)
    {
        printf("NO\n");
        return 0;
    }
    
    for(int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a < b)
        edges[a].push_back(b);
        else
        edges[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
        visited[i] = false;
    vector<int> dfs;
    dfs.push_back(1);
    while(!dfs.empty())
    {
        int curr = dfs.back();
        dfs.pop_back();
        if(visited[curr])
        {
            printf("NO\n");
            return 0;
        }

        visited[curr] = true;
        for(int i = 0; i < edges[curr].size(); i++)
        {
                dfs.push_back(edges[curr][i]);
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
