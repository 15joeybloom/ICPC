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
    int n, m;
    cin >> n >> m;

    for(int i = 0; m >= (i)%n+1; i = (i+1)%n)
    {
        m -= i+1;
    }

    cout << m << endl;
}
