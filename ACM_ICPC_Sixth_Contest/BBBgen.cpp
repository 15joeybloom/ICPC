#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    char a[1001],b[1001];

    char c = 'a';
    for(int i = 0; i < 1000; i++)
    {
        a[i] = c;
        b[i] = c;
        c++;
        if(c>'z')c='a';
    }

    a[999]++;
    a[1000] = 0;
    b[1000] = 0;

    printf("%s\n%s\n",a,b);

}
