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

int arr[100010];

int solve(int x)
{
    int i = 0;
    while(true)
    {
        i+= x;

        int checker = i;
        while(checker > 0)
        {
            if(checker % 10 != 1) goto cont;
            checker /= 10;
        }

        return ceil(log10(i));
        cont:;
    }
}
int main()
{
    for(int i = 0; i < 100000; i+= 10)
    {
        arr[i+1] = solve(i+1);
        arr[i+3] = solve(i+3);
        arr[i+7] = solve(i+7);
        arr[i+9] = solve(i+9);
    }
}
