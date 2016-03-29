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
    int n, a, b;
    cin >> n >> a >> b;

    int counter = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i-1 >= a && n-i <= b)
            counter++;
    }

    cout << counter << endl;
}
