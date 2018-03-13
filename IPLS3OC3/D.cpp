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

LL n;
LL board[2010][2010];
LL sum[4010];
LL diff[4010];


/*
void debug() {
    for (int i = 0; i < 2*n; i++)
        cout << sum[i] << " ";
    cout << endl;
    for (int i = 0; i < 2*n; i++)
        cout << diff[i] << " ";
    cout << endl;
}
*/

int main()
{
    //cin >> n;
    scanf("%lld", &n);

    memset(sum, 0, sizeof(sum));
    memset(diff, 0, sizeof(diff));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            //cin >> board[i][j];
            scanf("%lld", &board[i][j]);
            sum[i+j] += board[i][j];
            diff[i-j+n] += board[i][j];
        }

    LL oddx, oddr, oddc, evenx, evenr, evenc;
    oddx = evenx = 0;
    oddr = oddc = evenr = evenc = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            LL x = sum[i+j]+diff[i-j+n]-board[i][j];
            if ((i+j) % 2 == 1) {
                //cout << x << endl;
                if (x > oddx) {
                    oddx = x;
                    oddr = i;
                    oddc = j;
                }
            } else if (x > evenx) {
                evenx = x;
                evenr = i;
                evenc = j;
            }
        }

    printf("%lld\n",oddx+evenx);
    printf("%lld %lld %lld %lld\n", oddr+1, oddc+1, evenr+1, evenc+1);
    //cout << oddx+evenx << endl;
    //cout << oddr+1 << " " << oddc+1 << " " << evenr+1 << " " << evenc+1 << endl;

    //debug();
}
