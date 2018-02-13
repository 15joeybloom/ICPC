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

int a[100010];
int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int start = -1;
    for(int i = 1; i < n; i++)
    {
        if(a[i-1] > a[i])
        {
            start = i-1;
            break;
        }
    }

    if(start == -1)
    {
        printf("yes\n");
        printf("1 1\n");
        return 0;
    }

    int end = n-1;
    for(int i = start; i < n; i++)
    {
        if(a[i] < a[i+1])
        {
            end = i;
            break;
        }
    }

    if((start>0 && a[start-1] > a[end]) || (end < n-1 && a[start] > a[end+1]))
    {
        printf("no\n");
        return 0;
    }
    for(int i = end+1; i < n; i++)
    {
        if(a[i-1] > a[i])
        {
            printf("no\n");
            return 0;
        }
    }

    printf("yes\n");
    printf("%d %d\n", start+1, end+1);
}
