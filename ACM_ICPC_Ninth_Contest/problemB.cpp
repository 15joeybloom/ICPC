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
    int n;
    cin >> n;

    switch(n)
    {
        case 1:
            cout << 1 << endl;
            cout << 1 << endl;
            break;
        case 2:
            cout << 1 << endl;
            cout << 1 << endl;
            break;
        case 3:
            cout << 2 << endl;
            cout << 1 << ' ' << 3 << endl;
            break;
        case 4:
            cout << 4 << endl;
            cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << endl;
            break;
        default:
            cout << n << endl;
            if(n % 2 == 0) //even
            {
                int one = 1, half = n/2+1;
                cout << one++ << ' ' << half++;
                while(half <= n)
                {
                    cout << ' ' << one++ << ' ' << half++ ;
                }
            }
            else //odd
            {
                int one = 1, half = n/2+2;
                cout << one++;
                while(half <= n)
                {
                    cout << ' ' << half++ << ' ' << one++;
                }
            }
            cout << endl;
            break;
    }
}
