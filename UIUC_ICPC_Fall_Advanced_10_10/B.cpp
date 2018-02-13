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

typedef long long LL;

LL arr[10010];
int main()
{
    int N;
    cin >> N;

    int counter = 0;
    for(int i = 1; i <= sqrt(N); i++)
    {
        counter += N / i - (i-1);
    }

    cout << counter << endl;
}
