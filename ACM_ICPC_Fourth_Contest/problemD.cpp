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
    int A, B;
    char Sin[5000];
    bool S[5000];

    while(scanf("%d %d",&A, &B)!=EOF)
    {
        scanf("%s",&Sin);

        int n = 0, p = 0;

        for(int i = 0; Sin[i]!='\0'; i++)
        {
            if(Sin[i]=='B')
            {
                S[i] = true;
                p++;
            }
            else S[i] = false;

            n++;
        }

        int minCost = 0;
        int numToMove = 0;
        for(int i = p; i < n; i++)
        {
            if(S[i]) numToMove++;
        }
        minCost = numToMove*A;

        int curr = p;
        for(int i = 1; i <= numToMove; i++)
        {
            while(!S[curr]) curr++;
            
            int cost = (numToMove-i)*A;
            for(int j = curr; j >= p; j--)
            {

            }
        }

        
    }

}
