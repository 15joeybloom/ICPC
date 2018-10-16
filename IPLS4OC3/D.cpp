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

int djset[30010];
int freq[30010];

int find(int i) {
    if (djset[i] == i)
        return i;
    return djset[i] = find(djset[i]);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            djset[i] = i;
            freq[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            djset[find(A-1)] = find(B-1);
        }
        for (int i = 0; i < N; i++) {
            freq[find(i)]++;
        }
        int best = 0;
        for (int i = 0; i < N; i++) {
            best = max(best, freq[i]);
        }
        printf("%d\n", best);
    }
}
