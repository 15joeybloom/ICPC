#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

long long int sums[101][101];
int main()
{
    int N;
    cin >> N;

    for(int j = 0; j <= N; j++)
    {
        sums[0][j] = 0;
        sums[j][0] = 0;
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            sums[i][j] = sums[i-1][j]-sums[i-1][j-1]+sums[i][j-1]+x;
        }
    }

    long long int maxRect = LLONG_MIN;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = i+1; k <= N; k++)
                for(int l = j+1; l <= N; l++)
                {
                    maxRect = max(maxRect,sums[k][l]-sums[i][l]+sums[i][j]-sums[k][j]);
                }

    cout << maxRect << endl;
}
