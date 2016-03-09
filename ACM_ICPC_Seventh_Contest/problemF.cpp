#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int parent[1000000];

int find(int x)
{
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int r = 0; r < n; r++)
        for(int c = 0; c < m; c++)
            parent[r*m+c] = r*m+c;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            int x = r*m+c;
            char dir;
            scanf("%c", &dir);
            switch(dir)
            {
                case 'N':
                    parent[x] = find(x-m);
                    break;
                case 'E':
                    parent[x] = find(x+1);
                    break;
                case 'S':
                    parent[x] = find(x+m);
                    break;
                case 'W':
                    parent[x] = find(x-1);
                    break;
                default:
                    printf("Joey we got a problem %d", dir);
            }
        }
        scanf("\n");
    }

    int counter = 0;
    for(int i = 0; i < n*m; i++)
        if(parent[i] == i) counter++;

    printf("%d\n", counter);
}
