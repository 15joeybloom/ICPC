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
    int n, k;
    scanf("%d %d", &n, &k);

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        int y;
        scanf("%d", &y);

        if(5-y >= k)
            counter++;
    }

    printf("%d\n", counter/3);
}
