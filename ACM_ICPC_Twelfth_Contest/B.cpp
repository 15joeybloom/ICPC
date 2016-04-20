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

#define MAGIC 26
#define MOD     961748941

char s[1000005];
int robinkarp(int start, int end)
{
    int hash = 0;
    int n = end-start;
    for(int i = start; i < end; i++)
    {
        hash*= MAGIC;
        hash += s[i];
    }

    return hash % MOD;
}
int main()
{
    while(scanf("%s", s)!=EOF && s[0]!='.')
    {
        int n = strlen(s);
        
        int minLength = n;
        for(int i = n/2; i > 0; i--)
        {
            if(n % i) continue;

            bool good = true;
            int hash = robinkarp(0, i);
            for(int j = i; j < n; j+=i)
            {
                if(robinkarp(j,j+i) != hash)
                {
                    good = false;
                    break;
                }
            }
            if(good)
                minLength = i;
        }

        printf("%d\n", n/minLength);
    }
}
