#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define PYRLIM 1000000
struct pyr
{
    long int c;
    int b;
    char type;
};

bool operator<(const pyr &a, const pyr &b)
{
    if(a.c == b.c)
        return a.type < b.type;
    return a.c < b.c;
}
vector<long int> pyrs;
int main()
{
    long int pyrHeight = 1;
    for(long int i = 2; pyrHeight <= PYRLIM; i++)
    {
        pyrHeight += i * i;
        pyr p;
        p.c = pyrHeight;
        p.b = i;
        p.type = 'H';
        pyrs.push_back(p);
    }
    pyrHeight = 0;
    for(long int i = 2; pyrHeight <= PYRLIM; i+=2)
    {
        pyrHeight += i*i;
        pyr p;
        p.c = pyrHeight;
        p.b = i;
        p.type = 'L';
        pyrs.push_back(p);
    }
    pyrHeight = 1;
    for(long int i = 3; pyrHeight <= PYRLIM; i+=2)
    {
        pyrHeight += i*i;
        pyr p;
        p.c = pyrHeight;
        p.b = i;
        p.type = 'L';
        pyrs.push_back(p);
    }

    sort(pyrs.begin(), pyrs.end());

    long int c;
    while(scanf("%ld", &c)!=EOF && c)
    {
        
    }
}
