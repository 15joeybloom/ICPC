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
    char arr[105];

    scanf("%s", arr);

    string hello = "hello";
    int i = 0, j = 0;
    while(i < strlen(arr))
    {
        if(arr[i] == hello[j])
        {
            j++;
            if(j == 5)
                {
                printf("YES\n");
                return 0;
                }
        }
        i++;
    }
    printf("NO\n");
    return 0;
}
