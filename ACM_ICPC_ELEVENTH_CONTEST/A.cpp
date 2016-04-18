#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define PYRLIM 1000000
#define INF 0x7F7F7F7F
struct pyr
{
    long int c;
    int b;
    char type;
};

//int dp[PYRLIM+10];
//int largest[PYRLIM+10];
bool dp[400][PYRLIM+10];

bool operator<(const pyr &a, const pyr &b)
{
    if(a.c == b.c)
        return a.type < b.type;
    return a.c < b.c;
}
vector<pyr> pyrs;
int main()
{
    long int pyrCubes = 5;
    for(long int i = 2; pyrCubes <= PYRLIM; )
    {
        pyr p;
        p.c = pyrCubes;
        p.b = i;
        p.type = 'H';
        pyrs.push_back(p);
        i++;
        pyrCubes += i * i;
    }
    pyrCubes = 20;
    for(long int i = 4; pyrCubes <= PYRLIM; )
    {
        pyr p;
        p.c = pyrCubes;
        p.b = i;
        p.type = 'L';
        pyrs.push_back(p);
        i += 2;
        pyrCubes += i*i;
    }
    pyrCubes = 10;
    for(long int i = 3; pyrCubes <= PYRLIM; )
    {
        pyr p;
        p.c = pyrCubes;
        p.b = i;
        p.type = 'L';
        pyrs.push_back(p);
        i += 2;
        pyrCubes += i*i;
    }

    sort(pyrs.begin(), pyrs.end());

/*
    memset(dp, INF, sizeof(dp));
    memset(largest, -1, sizeof(dp));
    dp[0] = 0;
    */
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    //for(long int i = 0; i < pyrs.size(); i++)
    for(long int i = 1; i < pyrs.size(); i++)
    {
        for(long int j = PYRLIM; j >= 0; j--)
        {
            if(dp[i-1][j])
            {
                dp[i][j] = true;
                long int potential = j+pyrs[i-1].c;
                if(potential <= PYRLIM)
                {
                    dp[i][potential] = true;
                }
            }
            /*
            if(dp[j]!=INF)
            {
                long int potential = j+pyrs[i].c;
                if(potential <= PYRLIM)
                {
                    int newCount = dp[j]+1;
                    if(dp[potential] >= newCount)
                    {
                        dp[potential] = newCount; 
                        if(largest[potential] == -1)
                            largest[potential] = i;
                    }
                }
            }
            */
        }
    }

    long int c;
    for(int t = 1; scanf("%ld", &c)!=EOF && c; t++)
    {
        printf("Case %d:", t);

        if(dp[pyrs.size()-1][c])
        {
            for(int i = pyrs.size()-1; c; i--)
            {
                long int potential = c-pyrs[i-1].c;
                if(potential >= 0 && dp[i-1][potential])
                {
                    printf(" %d%c", pyrs[i-1].b, pyrs[i-1].type);
                    c = potential;
                }
            }
        }
        else
            printf(" impossible");
/*
        if(dp[c]==INF)
            printf(" impossible");
        else
        {
            for(int i = pyrs.size()-1; c; i--)
            {
                long int potential = c-pyrs[i].c;
                if(potential >= 0 && dp[potential] < dp[c] && largest[potential] < i)
                {
                    printf(" %d%c", pyrs[i].b, pyrs[i].type);
                    c = potential;
                }
            }
        }
        */

        printf("\n");
    }
}
