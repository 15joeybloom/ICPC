#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a[100000];
int n, m;
int main()
{
    int T = 0;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
        {
            a[i] = i+1;
        }

        for(int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);

            int i;
            for(i = 0; a[i]!=x; i++);

            printf("%d ", i);

            while(i > 0)
            {
                a[i] = a[i-1];
                i--;
            }
            a[0] = x;
        }

        printf("\n");
    }
}
