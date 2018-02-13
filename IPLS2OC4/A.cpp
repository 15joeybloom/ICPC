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

int main()
{
    int n;
    cin >> n;

    for( int i = 0; i < n; i++) {
        char in[110];
        scanf("%s", in);

        int m = strlen(in);
        if(m > 10) {
            printf("%c%d%c\n", in[0], m-2, in[m-1]);
        }
        else {
            printf("%s\n", in);
        }
    }
}
