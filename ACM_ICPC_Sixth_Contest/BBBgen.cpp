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

    char c = 0;
    for(int i = 0; i < 1000; i++)
    {
        a[i] = c;
        b[i] = c;
        c++;
    }

    a[999]++;

    printf("%s\n%s\n",a,b);

}
