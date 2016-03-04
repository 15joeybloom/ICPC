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
    int N;
    int A[10];
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int x = 0;
    for(int i = 1; i < (1<<N); i++)
    {
        int prev = 0, l = 0;
        for(int j = 0; j < N; j++)
        {
            if(i & (1<<j))
            {
                if(A[j] > prev)
                {
                    l++;
                    prev = A[j];
                }
                else goto mybreak;
            }

        }
        x = max(x,l);

mybreak:;
    }

    printf("%d\n",x);

}
