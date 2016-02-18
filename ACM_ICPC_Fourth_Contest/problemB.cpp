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
    long int n, m, a[1000];
    while(scanf("%ld %ld",&n,&m)!=EOF)
    {
	if(n /2 == 0 || m/2 == 0)
	{
		printf("Boring!\n");
		continue;
	}
        bool boring = false;
        for(int i = 0; i < 1000; i++)
        {
            a[i] = 0;
        }

        a[1] = n;
        for(int i = 2; a[i-1] != 1 && i < 1000; i++)
        {
            if(!n || !m || n%m)
            {
                boring = true;
                break;
            }
            else
            {
                a[i] = n/m;
                n /= m;
            }
        }
        if(boring)
        {
            printf("Boring!\n");
        }
        else
        {
            for(int i = 1; a[i] > 1 && i < 1000; i++)
            {
                printf("%ld ",a[i]);
            }
            printf("1\n");
        }
    }

}
