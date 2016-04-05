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
    int cases;
    cin >> cases;

    string dummy;
    getline(cin,dummy);
    getline(cin,dummy);
    for(int casee = 0; casee < cases; casee++)
    {
        string last;
        getline(cin,last);
        cout << last << endl;

        int level = 0;
        string current;
        while(getline(cin,current) && !current.empty())
        {
            int i;
            for(i = 0; i <= level; i++)
            {
                if(!last[i] || last[i] !=current[i])
                    break;
            }
            level = i;
            for(int j = 0; j < i; j++)
            {
                cout << ' ';
            }
            cout << current << endl;
            last = current;
        }

        if(casee < cases-1) cout << endl;
    }
}
