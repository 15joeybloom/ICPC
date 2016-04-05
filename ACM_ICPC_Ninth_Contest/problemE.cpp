#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

long long gcd(long long x, long long y)
{
    if(x == 0) return y;
    if(y == 0) return x;

    return gcd(y, x % y);
}
int main()
{
    long long x, y, a, b;
    cin >> x >> y >> a >> b;

    long long g = gcd(y, x);
    long long l = x*y/g;

    long long first = a/l*l;
    while(first < a) first += l;
    long long last = b/l*l;
    while(last > b) last -= l;

    cout << (last-first)/l + 1<< endl;
}
