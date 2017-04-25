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

int numbers[100][2];
int main()
{
    int n;
    scanf("%d", &n);

    while(n != -1) {
    numbers[0][0] = numbers[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", numbers[i], numbers[i]+1);
    }

    int dist = 0;
    for(int i = 1; i <= n; i++) {
        dist += numbers[i][0]*(numbers[i][1]-numbers[i-1][1]);
    }

    printf("%d miles\n", dist);
    scanf("%d", &n);
    }
}
