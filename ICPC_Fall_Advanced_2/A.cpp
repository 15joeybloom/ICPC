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

int main()
{
    int n;
    scanf("%d", &n);

    int freqs[10];
    memset(freqs, 0, sizeof(freqs));

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        freqs[x]++;
    }

    int groups = 0;
    groups += freqs[4];
    freqs[4] = 0;

    int threeones = min(freqs[3], freqs[1]);
    groups += threeones;
    freqs[3] -= threeones;
    freqs[1] -= threeones;

    groups += freqs[3];
    freqs[3] = 0;

    groups += freqs[2]/2;
    freqs[2] -= 2*(freqs[2]/2);

    if(freqs[2])
    {
        groups++;
        freqs[2] = 0;

        freqs[1] -= min(2, freqs[1]);
    }

    groups += freqs[1]/4;
    freqs[1] -= 4*(freqs[1]/4);

    if(freqs[1])
        groups++;

    printf("%d\n", groups);
}
