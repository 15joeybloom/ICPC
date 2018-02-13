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

#define MAXK 100010

typedef long long LL;

struct event {
    LL i;
    bool up;

    event(LL i, bool up) {
        this->i = i;
        this->up = up;
    }
    bool operator<(const event &lhs, const event &rhs) {
        return lhs.i < rhs.i;
    }
};

bool logs[MAXK];
char responses[MAXK]
LL guesses[MAXK];

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        LL k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            char resp[5];
            char yesno[20];
            cin >> resp >> guesses[i] >> yesno;
            responses[i] = resp[0];
            logs[i] = strcmp(yesno, "Yes") == 0;
        }
        vector<event> es;
        for (int i = 0; i < k; i++) {
            if (responses[i] == '<') {
                if (logs[i]) {
                    event e(i-1,false);
                    es.push_back(e);
                } else {
                    event e(i-1,true);
                    es.push_back(e);
                }
            } else if (responses[i] == '>') {
                if (logs[i]) {
                    event e(i,true);
                    es.push_back(e);
                } else {
                    event e(i,false);
                    es.push_back(e);
                }
            } else {
                if (logs[i]) {
                    event e(i-1,true);
                    event ee(i,false);
                    es.push_back(e);
                    es.push_back(ee);
                } else {
                    event e(i-1,false);
                    event ee(i,true);
                    es.push_back(e);
                    es.push_back(ee);
                }
            }
        }

        sort(e.begin(), e.end());

        LL besti = -1;
        LL best = -MAXK;
        LL running = 0;
        LL current = 0;
        int i = 0;
        while (i < e.size()) {
            current = e[i].i;
            while (e[i].i == current) {
                if (e[i].up) running++;
                else running--;
                i++;
            }

            if (running > best) {
                besti = current;
                best = running;
            }
        }

        for (int i = 0; i < k; i++) {
            if (responses[i] == '<') {
                if (logs[i]) {
                    event e(i-1,false);
                    es.push_back(e);
                } else {
                    event e(i-1,true);
                    es.push_back(e);
                }
            } else if (responses[i] == '>') {
                if (logs[i]) {
                    event e(i,true);
                    es.push_back(e);
                } else {
                    event e(i,false);
                    es.push_back(e);
                }
            } else {
                if (logs[i]) {
                    event e(i-1,true);
                    event ee(i,false);
                    es.push_back(e);
                    es.push_back(ee);
                } else {
                    event e(i-1,false);
                    event ee(i,true);
                    es.push_back(e);
                    es.push_back(ee);
                }
            }
        }
    }
}
