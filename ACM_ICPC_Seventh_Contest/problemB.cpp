#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char grid[52][52];

int main()
{
    int H, W;
    list<int> bfsx;
    list<int> bfsy;
    while(scanf("%d %d", &H, &W)!=EOF && H!= 0 && W!=0)
    {
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                scanf("%c",&grid[i][j]);
                if(grid[i][j] == 'A')
                {
                    bfsx.push_back(i);
                    bfsy.push_back(j);
                }
            }
            scanf("\n");
        }

    }

    char mymax = 'A'-1;
    while(!bfsx.empty())
    {
        int x = bfsx.front();
        int y = bfsy.front();
        bfsx.pop_front();
        bfsy.pop_front();

        mymax = grid[x][y];

        if(grid[x
    }


}
