#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define AND 0
#define OR 1
#define XOR 2
#define NOT 3
#define IN 4

struct Tree {
    int gate;
    int left;
    int right;
    bool value;
    bool contributing = false;
    int depth;
} nodes[1000010];

void printTree(int node) {
    for (int i = 0; i < nodes[node].depth; i++)
        printf("  ");
    switch (nodes[node].gate) {
        case AND:
            printf("AND");
            break;
        case OR:
            printf("OR");
            break;
        case XOR:
            printf("XOR");
            break;
        case NOT:
            printf("NOT");
            break;
        case IN:
            printf("IN");
    }
    printf(" id=%d value=%s contributing=%s\n",
        node,
        nodes[node].value ? "true" : "false",
        nodes[node].contributing ? "true" : "false");
    switch (nodes[node].gate) {
        case AND:
        case OR:
        case XOR:
            printTree(nodes[node].left);
            printTree(nodes[node].right);
            break;
        case NOT:
            printTree(nodes[node].left);
            break;
    }
}

bool evaluate() {
    vector<int> stk;
    stk.push_back(1);
    for (int i = 0; i < stk.size(); i++) {
        switch (nodes[stk[i]].gate) {
            case AND:
            case OR:
            case XOR:
                nodes[nodes[stk[i]].left].depth = nodes[stk[i]].depth + 1;
                nodes[nodes[stk[i]].right].depth = nodes[stk[i]].depth + 1;
                stk.push_back(nodes[stk[i]].left);
                stk.push_back(nodes[stk[i]].right);
                break;
            case NOT:
                nodes[nodes[stk[i]].left].depth = nodes[stk[i]].depth + 1;
                stk.push_back(nodes[stk[i]].left);
                break;
        }
    }

    while (!stk.empty()) {
        int i = stk.back();
        stk.pop_back();
        switch (nodes[i].gate) {
            case AND:
                nodes[i].value = nodes[nodes[i].left].value && nodes[nodes[i].right].value;
                break;
            case OR:
                nodes[i].value = nodes[nodes[i].left].value || nodes[nodes[i].right].value;
                break;
            case XOR:
                nodes[i].value = nodes[nodes[i].left].value != nodes[nodes[i].right].value;
                break;
            case NOT:
                nodes[i].value = !nodes[nodes[i].left].value;
                break;
        }
    }

    return nodes[1].value;
}

void contributing() {
    vector<int> stk;
    stk.push_back(1);
    while (!stk.empty()) {
        int i = stk.back();
        stk.pop_back();
        nodes[i].contributing = true;
        switch (nodes[i].gate) {
            case AND:
                if (nodes[nodes[i].right].value) {
                    stk.push_back(nodes[i].left);
                }
                if (nodes[nodes[i].left].value) {
                    stk.push_back(nodes[i].right);
                }
                break;
            case OR:
                if (!nodes[nodes[i].right].value) {
                    stk.push_back(nodes[i].left);
                }
                if (!nodes[nodes[i].left].value) {
                    stk.push_back(nodes[i].right);
                }
                break;
            case XOR:
                stk.push_back(nodes[i].left);
                stk.push_back(nodes[i].right);
                break;
            case NOT:
                stk.push_back(nodes[i].left);
                break;
        }
        
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        char gate[10];
        scanf("%s", gate);
        if (strcmp(gate, "AND") == 0) {
            nodes[i].gate = AND;
            scanf("%d %d\n", &nodes[i].left, &nodes[i].right);
        } else if (strcmp(gate, "OR") == 0) {
            nodes[i].gate = OR;
            scanf("%d %d\n", &nodes[i].left, &nodes[i].right);
        } else if (strcmp(gate, "XOR") == 0) {
            nodes[i].gate = XOR;
            scanf("%d %d\n", &nodes[i].left, &nodes[i].right);
        } else if (strcmp(gate, "NOT") == 0) {
            nodes[i].gate = NOT;
            scanf("%d\n", &nodes[i].left);
        } else {
            nodes[i].gate = IN;
            int x;
            scanf("%d\n", &x);
            nodes[i].value = x == 1;
        }
    }
    nodes[1].depth = 0;

    bool value = evaluate();
    contributing();
    //printTree(1);

    for (int i = 1; i <= n; i++) {
        if (nodes[i].gate == IN)
            printf("%d", nodes[i].contributing != value ? 1 : 0);
    }
    printf("\n");
}
