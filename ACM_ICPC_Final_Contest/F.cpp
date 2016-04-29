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
    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        char c[10];
        scanf("%s", c);

        if(strlen(c) > 3)
        {
            printf("3\n");
            continue;
        }
        int onediff = 0, twodiff = 0;
        if(c[0] != 'o') onediff++;
        if(c[1] != 'n') onediff++;
        if(c[2] != 'e') onediff++;
        if(c[0] != 't') twodiff++;
        if(c[1] != 'w') twodiff++;
        if(c[2] != 'o') twodiff++;

        if(onediff <= 1)
            printf("1\n");
        else
            printf("2\n");
    }
}
