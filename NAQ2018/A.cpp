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
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;

typedef unordered_map<int, pair<int, int> > index_t;
int n;
int cards[110][5][5];
unordered_set<int> cardset[110];
index_t indices[110];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d %d %d %d %d", &cards[i][j][0], &cards[i][j][1], &cards[i][j][2], &cards[i][j][3], &cards[i][j][4]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cardset[i].insert(cards[i][j][k]);
                indices[i][cards[i][j][k]] = make_pair(j, k);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // intersection
            unordered_set<int> intersection;
            for (int x : cardset[i]) {
                if (cardset[j].count(x)) {
                    intersection.insert(x);
                    //printf("%d ", x);
                }
            }
            //printf("\n");
            for (int tienumber : intersection) {
                unordered_set<int> others;
                int irow = indices[i][tienumber].first;
                int jrow = indices[j][tienumber].first;
                for (int k = 0; k < 5; k++) {
                    if (cards[i][irow][k] != tienumber)
                        others.insert(cards[i][irow][k]);
                    if (cards[j][jrow][k] != tienumber)
                        others.insert(cards[j][jrow][k]);
                }
                bool bingo = false;
                for (int ii = 0; ii < n; ii++) {
                    if (ii == i || ii == j) continue;

                    index_t ind = indices[ii];
                    bool card[5][5];
                    memset(card, 0, sizeof(card));
                    for (int other : others) {
                        auto coords = ind.find(other);
                        if (coords != ind.end())
                            card[coords->second.first][coords->second.second] = true;
                    }
                    for (int k = 0; k < 5; k++) {
                        bool row = true;
                        for (int l = 0; l < 5; l++) {
                            if (!card[k][l])
                                row = false;
                        }
                        if (row) {
                            bingo = true;
                            //printf("bingo %d %d\n", ii, k);
                        }
                    }
                }
                if (!bingo) {
                    printf("%d %d\n", i+1, j+1);
                    return 0;
                }
            }
        }
    }
    printf("no ties\n");
}
