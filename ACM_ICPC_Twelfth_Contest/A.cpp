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

int n;

typedef pair<char, int> pci;

bool comp1(const pci &a, const pci &b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool comp2(const pci &a, const pci &b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
pci ordered[305];
int main()
{
    int row;
    char in[305];
    bool first = true;
    while(scanf("%s %d", in, &row)!=EOF && row)
    {
        if(!first)
            printf("\n");
        row-=1;

        n = strlen(in);

        for(int i = 0; i < n; i++)
        {
            ordered[i].first = in[i];
            ordered[i].second = i;
        }

        sort(ordered, ordered+n, comp1);
        for(int i = 0; i < n; i++)
        {
            printf("%c", ordered[row].first);
            row = ordered[row].second;
        }
        printf("\n");
        first = false;
    }
}
