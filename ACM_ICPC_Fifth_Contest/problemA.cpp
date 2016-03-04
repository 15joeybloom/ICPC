#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

long long int x[1000000];

/*
void fill(long long int n)
{
    long long int a = 2*n;
    long long int b = (n+1);

    if(a < 1000000)
    {
        x[a] = x[n]+1;
        fill(a);
    }
    if(b < 3000000 && b%3==0)
    {
        b/=3;
        x[b] = x[n]+1;
        fill(b);
    }
    
}
*/

int main()
{
    //x[1] = 1;
    //fill(1L);

    for(long long int ii = 1; ii < 1000000; ii++)
    {
        long long int counter = 1, temp = ii;
        while(temp!=1)
        {
            if(temp%2) temp=3*temp+1;
            else temp/=2;

            counter++;
        }
        x[ii] = counter;
    }

    long long int i, j;
    while(scanf("%lld %lld", &i, &j)!=EOF)
    {
        long long int lower, greater;
        if(i < j)
        {
            lower = i;
            greater = j;
        }
        else
        {
            lower = j;
            greater = i;
        }
        long long int mymax = 0;
        for(long long int ii = lower; ii <= greater; ii++)
        {
            mymax = max(mymax, x[ii]);
        }

        printf("%lld %lld %lld\n",i,j,mymax);
    }
}
