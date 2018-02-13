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
typedef pair<LL,LL> PLL;
#define MAXN 500010

struct Node {
    Node *left, *right;
    LL a;
} arr[MAXN];

struct {
    bool operator()(Node const *x, Node const *y) const {
        return x->a < y->a;
    }
} nodeless;

void printRing(Node *zero) {
    Node *curr = zero->right;
    while (curr != zero) {
        cout << curr->a << " ";
        if (curr->right->left != curr)
            cout << " BROKEN HERE LOL ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{
    LL n;
    cin >> n;

    arr[0].a = 0;
    for (int i = 1; i <= n; i++) {
        LL a;
        cin >> a;
        arr[i].a = a;
    }
    for (int i = 1; i < n; i++) {
        arr[i].left = &arr[i-1];
        arr[i].right = &arr[i+1];
    }
    arr[0].left = &arr[n];
    arr[0].right = &arr[1];
    arr[n].left = &arr[n-1];
    arr[n].right = &arr[0];

    vector<Node*> nodes;
    for (int i = 2; i < n; i++) {
        nodes.push_back(&arr[i]);
    }
    sort(nodes.begin(), nodes.end(), nodeless);
    LL score = 0;
    for (Node *n : nodes) {
        score += min(n->left->a, n->right->a);
        n->left->right = n->right;
        n->right->left = n->left;
        printRing(arr);
    }
    cout << score << endl;
}
