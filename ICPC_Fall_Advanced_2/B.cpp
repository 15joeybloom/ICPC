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

char board[1010][1010];
char counted[1010][1010];
int component[1010][1010];
map<int, int> componentCount;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++)
    {
        scanf("%s", &board[i][1]);
    }

    memset(counted, 0, sizeof(counted));
    memset(component, 0, sizeof(component));
    int components = 0;

    queue<pair<int, int> > bfs;
    for(int i = 2; i < n; i++)
        for(int j = 2; j < m; j++)
        {
            if(!counted[i][j] && board[i][j] == '.')
            {
                components++;
                componentCount[components] = 0;
                bfs.push(make_pair(i, j));
                while(!bfs.empty())
                {
                    pair<int, int> coords = bfs.front();
                    bfs.pop();

                    if(counted[coords.first][coords.second]) continue;

                    component[coords.first][coords.second] = components;

                    if(board[coords.first][coords.second+1] == '.')
                    {
                        if(!counted[coords.first][coords.second+1])
                            bfs.push(make_pair(coords.first, coords.second+1));
                    }
                    else
                        componentCount[components]++;
                    if(board[coords.first][coords.second-1] == '.')
                    {
                        if(!counted[coords.first][coords.second-1])
                            bfs.push(make_pair(coords.first, coords.second-1));
                    }
                    else
                        componentCount[components]++;
                    if(board[coords.first+1][coords.second] == '.')
                    {
                        if(!counted[coords.first+1][coords.second])
                            bfs.push(make_pair(coords.first+1, coords.second));
                    }
                    else
                        componentCount[components]++;
                    if(board[coords.first-1][coords.second] == '.')
                    {
                        if(!counted[coords.first-1][coords.second])
                            bfs.push(make_pair(coords.first-1, coords.second));
                    }
                    else
                        componentCount[components]++;

                    counted[coords.first][coords.second] = true;
                }
            }
        }

    for(int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", componentCount[component[x][y]]);
    }
}
