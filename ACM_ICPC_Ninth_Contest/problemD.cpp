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
    int w;
    cin >> w;

    if(w == 2)
        cout << "NO" << endl;
    else cout << (w%2 ? "NO" : "YES") << endl;
}
