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
int main()
{
    LL N, K;
    cin >> N >> K;

    map<LL, LL> freq;
    for (int i = 0; i < N; i++) {
        LL a, b;
        cin >> a >> b;
        if(!freq.count(a))
            freq[a] = 0;
        freq[a] += b;
    }

    map<LL, LL>::iterator it;
    LL k = 1;
    for (it = freq.begin(); k <= K && it != freq.end(); it++) {
        k += it->second;
    }
    it--;
    cout << it->first << endl;
}
