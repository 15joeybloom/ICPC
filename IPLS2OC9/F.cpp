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

#define MAXN 2000010
typedef long long LL;

string pattern;
LL kmp[MAXN];
int main()
{
    string path1, path2;
    getline(cin, path1);
    getline(cin, path1);
    getline(cin, path2);

    string::reverse_iterator it;
    for (it = path1.rbegin(); it != path1.rend(); it++) {
        switch(*it) {
            case 'N':
                pattern.push_back('S');
                break;
            case 'S':
                pattern.push_back('N');
                break;
            case 'E':
                pattern.push_back('W');
                break;
            case 'W':
                pattern.push_back('E');
                break;
        }
    }
    pattern.append(path2);

    kmp[0] = 0;
    for (int i = 1; i < pattern.size(); i++) {
        LL j = i-1;
        while (j >= 0 && pattern[i] != pattern[kmp[j]])
            j = kmp[j]-1;
        if (j < 0)
            kmp[i] = 0;
        else
            kmp[i] = kmp[j]+1;

        //cout << kmp[i] << " ";
    }
    //cout << endl << pattern << endl;

    if (kmp[pattern.size()-1] > 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
