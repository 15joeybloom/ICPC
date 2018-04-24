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

int a[100010];
int partialsums[100010];
int p[100010];
int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", a+i, p+i);
    }
    partialsums[0] = a[0];
    for(int i = 1; i < n; i++) {
        partialsums[i] = a[i]+partialsums[i-1];
    }

    int lastfed = n;
    int cost = 0;
    for(int price = 1; price <= 100; price++) {
        for(int i = 0; i < lastfed; i++) {
            if(p[i] == price) {
                cost += price*(partialsums[lastfed-1]-partialsums[i-1]);
                lastfed = i;
                break;
            }
        }
    }
    printf("%d\n", cost);
}
