#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int A[10001];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= 10000; i++)
        A[i] = -1;

    list<int> bfs;
    A[n] = 0;
    bfs.push_back(n);
    while(!bfs.empty())
    {
        int x = bfs.front();
        bfs.pop_front();
        if(x > 1 && A[x-1] == -1)
        {
            bfs.push_back(x-1);
            A[x-1]=A[x]+1;
        }
        if(x <= 5000 && A[2*x] == -1)
        {
            bfs.push_back(2*x);
            A[2*x]=A[x]+1;
        }
    }

    printf("%d\n", A[m]);
}
