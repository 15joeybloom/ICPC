#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<long int, long long int> mymap;

long long int max_dols(long int n)
{
    if(mymap.count(n)) return mymap[n];

    long long int myval = max((long long int)n, max_dols(n/2)+max_dols(n/3)+max_dols(n/4));
    mymap[n] = myval;
    return myval;
}
int main()
{
    long int n;
    mymap[0] = 0;
    mymap[1] = 1;
    while(scanf("%ld",&n)!=EOF)
    {
        //mymap[2] = 2;
        printf("%lld\n",max_dols(n));
    }

}
