#include <cctype>
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
    char in[200];
    scanf("%s", in);

    int n = strlen(in);

    int low = 0, up = 0;
    for(int i = 0; i < n; i++)
    {
        if(islower(in[i]))
            low++;
        else
            up++;
    }

    if(up > low)
    {
        for(int i = 0; i < n; i++)
            printf("%c", toupper(in[i]));
    }
    else
        for(int i = 0; i < n; i++)
            printf("%c", tolower(in[i]));

    printf("\n");
}
