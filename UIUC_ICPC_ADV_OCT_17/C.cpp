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

typedef unsigned long long LL;

LL quickpower(LL B, LL P, LL M)
{
    if(P == 0)
        return 1;
    if(P & 1)
    {
        return (B * quickpower(B, P-1, M))%M;
    }
    else
    {
        LL x= quickpower(B, P>>1, M);
        return (x*x)%M;
    }
}
int main()
{
    LL B, P, M;
    while(true)
    {
        int res = scanf("%lld %lld %lld", &B, &P, &M);
        if(res != 3) return 0;

        if(B == 0)
        {
            printf("0\n");
            continue;
        }
        else if(P == 0)
        {
            printf("1\n");
            continue;	
        } 
        printf("%lld\n", quickpower(B, P, M));
    }
}
