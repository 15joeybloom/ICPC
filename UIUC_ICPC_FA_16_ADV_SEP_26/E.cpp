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

char input[1000010];
int main()
{
    scanf("%s", input);

    int n = strlen(input);

    char *point = strchr(input, '.');
    char *first = input;
    while(*first == '0' || first == point)
    {
        first++;
    }

    char *lastdig = input+n-1;
    while(lastdig == point || *lastdig == '0')
        lastdig--;

    if(first > lastdig)
    {
        printf("0\n");
        return 0;
    }

    if(first == lastdig)
    {
        printf("%c", *first);
    }
    else
    {
        lastdig[1]=0;
        //printf("%c.%s", *first, first+1);
        printf("%c.", *first);
        for(char *ptr = first+1; *ptr; ptr++)
            if(isdigit(*ptr))
                printf("%c", *ptr);
    }

    int exponent;
    if(point)
        exponent = point - first;
    else
        exponent = (input-first)+n;
    if(exponent > 0) exponent--;
    if(exponent != 0)printf("E%d", exponent);

    printf("\n");

    //last - first + (point == NULL);
}
