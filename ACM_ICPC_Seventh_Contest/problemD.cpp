#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int n, x[101];
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);

        x[a] = i;
    }

    for(int i = 1; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("%d\n",x[n]);

}
