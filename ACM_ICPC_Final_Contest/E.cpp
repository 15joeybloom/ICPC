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
    scanf("%d\n", &n);

    int counter  = 0;
    char c;
    while(scanf("%c", &c)!=EOF && c == '1')
        counter++;

    if(c == '0') counter++;

    printf("%d\n", counter);
}
