#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int A[2001][2001];
int v[2000];
int N;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    for(int i = 0; i < N; i++)
    {
        A[0][i] = N*v[i];
    }
    for(int i = 1; i < N; i++)
    {
        //A[i][0] = A[i-1][0]+(N-i)*v[i];
        for(int j = 0; j < N-i; j++)
        {
            A[i][j] = max( A[i-1][j]+(N-i)*v[i+j] , A[i-1][j+1]+(N-i)*v[j] );
        }
    }
    printf("%d\n", A[N-1][0]);

}
