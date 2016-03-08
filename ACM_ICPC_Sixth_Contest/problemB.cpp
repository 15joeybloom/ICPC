#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int A[1001][1001];
int main()
{
    string a, b;

    while(!getline(cin, a).eof())
    {
        getline(cin, b);
        int N = a.length(), M = b.length();

        for(int i = 0; i < N; i++)
            A[i][0] = 0;
        for(int i = 0; i < M; i++)
            A[0][i] = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(a[i]==b[j])
                    A[i+1][j+1] = 1+A[i][j];
                else
                    A[i+1][j+1] = max(A[i][j+1],A[i+1][j]);
            }
        }

        printf("%d\n", A[N][M]);
    }

}
