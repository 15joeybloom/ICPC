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

string in1, in2;
string rev;
vector<int> x;
int main()
{
    int n;
    cin >> n;
    n--;
    cin >> in1 >> in2;

    for (int i = n-1; i >= 0; i--) {
        switch(in1[i]) {
            case 'N':
                rev += 'S';
                break;
            case 'S':
                rev += 'N';
                break;
            case 'W':
                rev += 'E';
                break;
            case 'E':
                rev += 'W';
                break;
            default:
                cout << "uh oh" << endl;
        }
    }
    rev += in2;
    int j = 0;
    x.push_back(0);
    for (int i = 1; i < rev.size(); i++) {
        while (j != 0 && rev[i] != rev[j])
            j = x[j-1];
        if (rev[i] == rev[j]) {
            x.push_back(j+1);
            j++;
        }
        else
            x.push_back(0);
    }
    /*
    cout << rev << endl;
    for (int xx : x)
        cout << xx << " ";
    cout << endl;
    */
    if (x[2*n-1] > 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
