#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    long int n, k, l, c, d, p, nl, np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

   long  int drink = k*l;
    long int drinkservings = drink/nl;
    long int slices = c*d;

    long int saltservings = p/np;

    cout << min(drinkservings, min(slices, saltservings))/n << endl;

}
