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

int boxes[25];
struct item
{
    double ratio;
    int cost, rating;
} ;

bool operator<(const item& a, const item& b)
{
    return a.ratio < b.ratio;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int T = 0; T < t; T++)
    {
        memset(boxes, false, sizeof(boxes));

        item items[22][22];
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 0; i < n; i++)
            scanf("%d", &boxes[i]);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &items[i][j].cost);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &items[i][j].rating);
                items[i][j].ratio = (double)items[i][j].rating/items[i][j].cost;
            }
        
        int maxRating = 0;
        for(int which = 1; which < (1 << n); which++)
        {
            item sortMe[500];

            int j = 0, spent = 0;
            int rating = 0;
            for(int i = 0; i < n; i++)
            {
                if(which & (1 << (i-1)))
                {
                    for(int k = 0; k < m; k++)
                        sortMe[j++] = items[i][k];
                    spent += boxes[i];
                }
            }

            sort(sortMe, sortMe+j);

            int l = 0;
            while(l < j && spent < k)
            {
                if(sortMe[l].cost + spent <= k)
                {
                    rating += sortMe[l].rating;
                    spent += sortMe[l].cost;
                }
                l++;
            }

            maxRating = max(maxRating, rating);
        }

        printf("%d\n", maxRating);
    }
}
