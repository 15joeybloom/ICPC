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
    int H;
    char path[50];
    memset(path, 0, sizeof(path));
    scanf("%d %s", &H, path);

    int depth = strlen(path);

    LL x = 1;
    for(int i = 0; i < depth; i++)
    {
        x <<= 1;
        if(path[i] == 'R')
            x++;
    }

    printf("%d\n", (1<<(H+1))-x);
}
