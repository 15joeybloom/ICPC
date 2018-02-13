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

int triangle[110][110];
int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            scanf("%d", &triangle[i][j]);
        }
    }

    for(int i = 2; i <= N; i++)
    {
        triangle[i][1] += triangle[i-1][1];
        for(int j = 2; j < i; j++)
        {
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        triangle[i][i] += triangle[i-1][i-1];
    }

    int maxsum = 0;
    for(int i = 1; i <= N; i++)
    {
        maxsum = max(maxsum, triangle[N][i]);
    }

    printf("%d\n", maxsum);
}
