#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

char N = 'N', E='E',W='W',S='S',R='R',L='L';

bool scent[51][51];
int main()
{
    int i, j;
    scanf("%d %d", &i, &j);
    
    int ii, ij;
    char dir;
    while(scanf("%d%d %c",&ii,&ij,&dir)!=EOF)
    {
        char inst[100];
        for(int iii = 0; iii < 100; iii++)
        {
            inst[iii] = 0;
        }
        scanf("%s", inst);

        bool lost = false;
        for(int iii = 0; inst[iii]; iii++)
        {
            if(inst[iii] == R)
            {
                if(dir == N)
                {
                    dir = E;
                }
                else if(dir == E) dir = S;
                else if(dir == S) dir = W;
                else if(dir == W) dir = N;
            }
            else if(inst[iii] == L)
            {
                if(dir == N) dir = W;
                else if(dir == W) dir = S;
                else if(dir == S) dir = E;
                else dir = N;
            }
            else if(scent[ii][ij]){}
            else
            {
                if(dir == N)
                {
                    if(ij+1 > j) lost = true;
                    else ij++;
                }
                if(dir == E)
                {
                    if(ii+1 > i) lost = true;
                    else ii++;
                }
                if(dir == S)
                {
                    if(ij-1 < 0) lost = true;
                    else ij--;
                }
                if(dir == W)
                {
                    if(ii-1 < 0) lost = true;
                    else ii--;
                }
                if(lost)
                {
                    scent[ii][ij] = true;
                    goto losthim;
                }
            }
        }
        losthim:
        printf("%d %d %c", ii, ij, dir);
        if(lost) printf(" LOST");
        printf("\n");

    }
}
