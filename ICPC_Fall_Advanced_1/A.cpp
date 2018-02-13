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

map<string, int> freqs;
int main()
{
    string line;
    int count = 0;

    while(getline(cin, line) && line.size() > 0)
    {
        count++;
        if(freqs.count(line))
            freqs[line]++;
        else
            freqs[line] = 1;
    }

    map<string, int>::iterator it;
    for(it = freqs.begin(); it != freqs.end(); it++)
    {
        printf("%s %.4f\n", it->first.c_str(), it->second / (float)count * 100);
    }
}
