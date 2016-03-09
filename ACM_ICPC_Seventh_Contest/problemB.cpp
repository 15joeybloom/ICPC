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

int xs[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
int ys[8] = { -1, 0, 1, 1, 1, 0, -1, -1};

char grid[52][52];
bool visited[52][52];

int main()
{
    int H, W;
    list<int> bfsx;
    list<int> bfsy;
    for(int cas = 1; scanf("%d %d", &H, &W)!=EOF && H!= 0 && W!=0; cas++)
    {
        for(int i = 0; i <= H; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                grid[j][i] = 0;
                visited[j][i] = false;
            }
        }
        for(int i = 1; i <= H; i++)
        {
            scanf("\n");
            for(int j = 1; j <= W; j++)
            {
                scanf("%c",&grid[j][i]);
                if(grid[j][i] == 'A')
                {
                    bfsx.push_back(j);
                    bfsy.push_back(i);
                }
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

            for(int i = 0; i < 8; i++)
            {
                int tempx = x+xs[i];
                int tempy = y+ys[i];
                if(!visited[tempx][tempy] && grid[tempx][tempy] == grid[x][y]+1)
                {
                    bfsx.push_back(tempx);
                    bfsy.push_back(tempy);
                    visited[tempx][tempy] = true;
                }
            }
        }

        printf("Case %d: %d\n", cas, mymax-'A'+1);
    }

}
