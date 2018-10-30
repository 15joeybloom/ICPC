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

struct node {
    LL p;
    LL depth;
    LL height;
    LL score;
    vector<LL> children;
    bool pass1 = false;
} nodes[1000010];

int main()
{
    LL n, k;
    scanf("%lld %lld", &n, &k);
    for (LL i = 2; i <= n; i++) {
        scanf("%lld", &nodes[i].p);
        nodes[nodes[i].p].children.push_back(i);
    }
    nodes[1].p = 0;
    nodes[0].depth = 0;

    vector<LL> stk;
    stk.push_back(1);
    while (!stk.empty()) {
        LL i = stk.back();
        if (nodes[i].pass1) {
            stk.pop_back();
            nodes[i].score = 1;
            LL best = 0;
            for (LL j : nodes[i].children) {
                if (nodes[j].height < k)
                    nodes[i].score += nodes[j].score;
                else
                    best = max(best, nodes[j].score);
                nodes[i].height = max(nodes[i].height, nodes[j].height);
            }
            nodes[i].height++;
        } else {
            nodes[i].pass1 = true;
            nodes[i].depth = nodes[nodes[i].p].depth + 1;
            if (nodes[i].children.empty()) {
                stk.pop_back();
                nodes[i].height = 0;
            } else {
                for (LL j : nodes[i].children)
                    stk.push_back(j);
            }
        }
    }

    /*
    for (LL i = 1; i <= n; i++) {
        printf("Node %lld is at depth %lld, its subtree is height %lld\n", i, nodes[i].depth, nodes[i].height);
    }
    */


}
