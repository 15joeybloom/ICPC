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
    vector<int> v;

    v.push_back(1);
    
    vector<int>::iterator it = v.begin();
    vector<int>::iterator eraseStart = it;
    vector<int>::iterator eraseEnd = v.end();
    it++;

    v.erase(eraseStart,eraseEnd);

    cout << v.size() << endl;

}
