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

int N;
int day[25], sunrise[25], sunset[25];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> day[i] >> sunrise[i] >> sunset[i];

    int maxday = 0;
    for (int i = 0; i < N; i++)
        maxday = max(maxday, day[i]);

    for (int t = 0; t < 1825*maxday; t++) {
        bool good = true;
        for (int i = 0; i < N; i++) {
            int local = t % day[i];
            if (sunrise[i] < sunset[i]) {
                if (sunrise[i] < local && local < sunset[i]) {
                    good = false;
                    break;
                }
            }
            else if (local < sunset[i] || sunrise[i] < local) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << t << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}
