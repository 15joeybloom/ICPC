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

long long pattern(long long a) {
    if (a < 10) {
        return a & 1;
    }
    return (pattern(a/10) << 1) | (a & 1);
}

int freq[300010];
int main()
{
    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; i++) {
        char q;
        long long a;
        scanf("%c %lld\n", &q, &a);

        if (q == '+') {
            freq[pattern(a)]++;
        }
        else if (q == '-') {
            freq[pattern(a)]--;
        }
        else {
            printf("%d\n", freq[pattern(a)]);
        }
    }
}
