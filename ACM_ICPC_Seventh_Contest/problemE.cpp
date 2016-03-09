#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool hasChar[26];
char c[101];
int main()
{
    for(int i = 0; i < 26; i++)
        hasChar[i] = false;

    scanf("%s",c);

    int i = 0, sum = 0;
    while('a' <= c[i] && c[i] <= 'z')
    {
        if(!hasChar[c[i]-'a'])
        {
            hasChar[c[i]-'a'] = true;
            sum++;
        }
        i++;
    }

    if(sum % 2 == 1)
        printf("IGNORE HIM!\n");
    else
        printf("CHAT WITH HER!\n");
}
