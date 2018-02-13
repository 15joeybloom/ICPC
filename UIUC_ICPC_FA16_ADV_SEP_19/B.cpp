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

typedef pair<int, int> pii;
int param;
bool pred(const pii& edge)
{
    return edge.first == param;
}
set<int> ns;
set<int> currentSet;
list<pii> edges;
vector<int> soln;
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        ns.insert(i);

    for(int i = 0; i < K; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);

        currentSet.insert(B);
        edges.push_back(make_pair(A, B));
    }
    if(N == 1)
    {
        printf("0\n");
        return 0;
    }
    if(K == 0)
    {
        printf("back to the lab\n");
        return 0;
    }

    while(edges.size() > 0)
    {
        currentSet = ns;
        list<pii>::iterator it;
        for(it = edges.begin(); it != edges.end(); it++)
        {
            currentSet.erase(it->second);
        }

    if(currentSet.size() > 1)
    {
        printf("back to the lab\n");
        return 0;
    }

        param = *currentSet.begin();
        soln.push_back(param);
        edges.remove_if(pred);
        ns.erase(param);
    }

    for(int i = 0; i < soln.size(); i++)
    {
        printf("%d ", soln[i]);
    }

    printf("%d\n", *ns.begin());
}
