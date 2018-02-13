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

char board[60][60];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%s", board[i]);

    int top = 0;
    for(int i = 0; i < n; i++)
    {
        top = i;
        for(int j = 0; j < m; j++)
            if(board[i][j] == '*')
                goto topdone;
    }
    topdone:
    
    int bottom = 0;
    for(int i = n-1; i >= 0; i--)
    {
        bottom = i;
        for(int j = 0; j < m; j++)
            if(board[i][j] == '*')
                goto bottomdone;
    }
    bottomdone:

    int left = 0;
    for(int j = 0; j < m; j++)
    {
        left = j;
        for(int i = 0; i < n; i++)
            if(board[i][j] == '*')
                goto leftdone;
    }
    leftdone:

    int right = 0;
    for(int j = m-1; j >= 0; j--)
    {
        right = j;
        for(int i = 0; i < n; i++)
            if(board[i][j] == '*')
                goto rightdone;
    }
    rightdone:

    for(int i = top; i <= bottom; i++)
    {
        for(int j = left; j <= right; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }

}
