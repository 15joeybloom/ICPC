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

int freq['z'];

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;

    else
        return gcd(b, a%b);
}
int main()
{
    int k;
    char arr[1005];

    scanf("%d %s", &k, arr);
    
    int n = strlen(arr);
    int numsubs = n/k;
    int temp = k;
    k = numsubs;
    numsubs = temp;
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int mygcd = freq['a'];
    for(char i = 'b'; i <= 'z'; i++)
    {
        mygcd = gcd(mygcd, freq[i]);
    }

    if(mygcd % numsubs)
    {
        printf("-1\n");
        return 0;
    }

    char subs[1005];
    int a = 0;
    for(char i = 'a'; i <= 'z'; i++)
    {
        for(int j = freq[i]/numsubs; j > 0; j--)
        {
            subs[a++] = i;
        }
    }
    subs[a] = '\0';

    for(int i = 0; i < numsubs; i++)
        printf("%s", subs);

    printf("\n");
}
