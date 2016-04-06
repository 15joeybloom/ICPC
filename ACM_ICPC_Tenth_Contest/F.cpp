#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

long long int cubes[10002];

int x[10002];
int y[10002];
int main()
{
    for(long long int i = 0; i <= 10000; i++)
    {
        x[i]=-1;
        y[i]=-1;
        cubes[i] = i*i*i;
        //if(cubes[i] < 0) cout << "damn. i="<<i<<" i^3="<<cubes[i] << endl;
    }

    for(int i = 10000; i >= 0; i--)
    {
        for(int j = i; cubes[j]-cubes[i]<10000 && j <= 10000; j++)
        {
            int diff = cubes[j]-cubes[i];
            x[diff]=j;
            y[diff]=i;
        }
    }

    int N;
    while(scanf("%d",&N)!=EOF && N)
    {
        if(x[N]<0&&y[N]<0)
            printf("No solution\n");
        else
            printf("%d %d\n", x[N], y[N]);
    }
}
