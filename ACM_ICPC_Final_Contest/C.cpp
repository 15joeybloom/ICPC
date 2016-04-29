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

char board[10][10];
int main()
{
    for(int i = 1; i <= 8; i++)
        scanf("%s", &board[i][1]);

    int minA = 100, minB = 100;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(board[i][j] == 'W')
            {
                bool good = true;
                for(int k = i-1; k >= 1; k--)
                {
                    if(board[k][j] != '.')
                        good = false;
                }
                if(good)
                    minA = min(minA, i-1);
            }
            if(board[i][j] == 'B')
            {
                bool good = true;
                for(int k = i+1; k <= 8; k++)
                {
                    if(board[k][j] != '.')
                        good = false;
                }
                if(good)
                    minB = min(minB, 8-i);
            }
        }
    }

    if(minB < minA)
        printf("B\n");
    else
        printf("A\n");
}
