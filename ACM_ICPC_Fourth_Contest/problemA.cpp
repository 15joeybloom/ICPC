#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int hin,min,x;

    scanf("%d:%d",&hin,&min);
    scanf("%d",&x);

    min += x;
    hin += min / 60;
    min %= 60;
    hin %= 24;

    printf("%02d:%02d\n",hin,min);


}
