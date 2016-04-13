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
    int T;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        vector<long long int> L;
        while(true)
        {
            long long int x;
            cin >> x;

            if(x)
                L.push_back(x);
            else
                break;
        }

        sort(L.rbegin(), L.rend());

        long long int cost = 0;
        for(int i = 0; i < L.size() && cost <= 5000000; i++)
        {
            int x = 2;
            for(int j = 0; j <= i; j++)
                x *= L[i];

            cost += x;
        }

        if(cost > 5000000)
            cout << "Too expensive" << endl;
        else
            cout << cost << endl;
    }
}
