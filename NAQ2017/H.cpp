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

long double x[200], y[200], t[200];
int main()
{
    int n;
    long double T;
    scanf("%d %llf", &n, &T);

    for(int i = 0; i < n; i++)
    {
        scanf("%llf %llf %llf", x+i, y+i, t+i);
    }

    long double expected = 0;
    for(int i = 1; i < n; i++) {
        expected += hypot(x[i]-x[i-1],y[i]-y[i-1]);
    }

    long double actual = 0;
    long double lastx = x[0], lasty = y[0], lastt = 0;
    for(int i = 1; i < n; i++) {
        if (lastt + T < t[i]) {
            long double thisx = x[i-1] + (x[i]-x[i-1])*(lastt+T-t[i-1])/(t[i]-t[i-1]);
            long double thisy = y[i-1] + (y[i]-y[i-1])*(lastt+T-t[i-1])/(t[i]-t[i-1]);
            actual += hypot(thisx-lastx, thisy-lasty);

            long double nextt = floor(t[i]/T)*T;
            long double nextx = x[i-1] + (x[i]-x[i-1])*(nextt-t[i-1])/(t[i]-t[i-1]);
            long double nexty = y[i-1] + (y[i]-y[i-1])*(nextt-t[i-1])/(t[i]-t[i-1]);
            actual += hypot(nextx-thisx, nexty-thisy);

            lastt = nextt;
            lastx = nextx;
            lasty = nexty;
        }
    }

    actual += hypot(x[n-1]-lastx, y[n-1]-lasty);
    printf("%.8llf\n", (expected-actual)/expected*100);
}
