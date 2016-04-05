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
    int n, m, minr = INT_MAX, maxr = 0, minw = INT_MAX;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        minr = min(minr,a);
        maxr = max(maxr,a);
    }
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        
        minw = min(minw, b);
    }

    int tl = max(2*minr, maxr);
    if(tl < minw)
        cout << tl << endl;
    else
        cout << -1 << endl;
}
