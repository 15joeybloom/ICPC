#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

long int x[1000000];

/*
void fill(long int n)
{
    long int a = 2*n;
    long int b = (n+1);

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

    for(long int ii = 1; ii < 1000000; ii++)
    {
        long int counter = 1, temp = ii;
        while(temp!=1)
        {
            if(temp%2) temp=3*temp+1;
            else temp/=2;

            counter++;
        }
        x[ii] = counter;
    }

    long int i, j;
    while(scanf("%ld %ld", &i, &j)!=EOF)
    {
        long int mymax = 0;
        for(long int ii = i; ii <= j; ii++)
        {
            mymax = max(mymax, x[ii]);
        }

        printf("%d %d %d\n",i,j,mymax);
    }
}
