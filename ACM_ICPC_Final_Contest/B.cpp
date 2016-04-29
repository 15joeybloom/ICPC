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
    long long int n;
    scanf("%lld", &n);

    long long int base = n/2;
    if(n%2 == 1)
    {
        base -= n;
    }

    printf("%lld\n", base);
}
