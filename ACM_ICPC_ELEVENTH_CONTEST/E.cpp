#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF && n)
    {
        int answer = n/2;
        printf("%d\n", answer);
    }
}
