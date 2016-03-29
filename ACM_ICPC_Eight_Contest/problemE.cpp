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
    int H, U, D, F;
    while(scanf("%d %d %d %d", &H, &U, &D, &F)!=EOF && H)
    {
        int day = 0;
        double s = 0;
        double u = U;
        double ff = F/100.0 * U;

        while(true)
        {
            day++;

            if(u > 0) s += u;

            if(s > H) break;

            s -= D;
            if(s < 0) break;

            u -= ff;
        }

        if(s > 0) printf("success on day %d\n", day);
        else printf("failure on day %d\n", day);
    }
}
