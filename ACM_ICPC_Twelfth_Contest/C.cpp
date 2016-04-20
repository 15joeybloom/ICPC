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
    char one[105], two[105];
    scanf("%s %s", one, two);
    
    reverse(one, one+strlen(one));

    for(int i = 0; i < strlen(one); i++)
    {
        if(one[i] != two[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

