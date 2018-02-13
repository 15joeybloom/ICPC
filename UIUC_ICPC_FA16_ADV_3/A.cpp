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
#include <utility>
using namespace std;

typedef std::pair<int,int> pii;
double norm(const pii &one)
{
    return sqrt(one.first*one.first + one.second*one.second);
}
double cross(const pii &one, const pii &two)
{
    return one.first*two.second - one.second*two.first;
}
int dot(const pii &one, const pii &two)
{
 return one.first * two.first + one.second*two.second;
}
bool leftcomp(const pii &one, const pii &two)
{
    return one.second/(one.first+1e-8) < two.second/(two.first+1e-8);
}
bool rightcomp(const pii &one, const pii &two)
{
    return one.second/(one.first-1e-8) < two.second/(two.first-1e-8);
}

pii neg[100010], pos[100010];
int main()
{
    int n;
    scanf("%d", &n);

    int lefts = 0, rights = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if(x > 0 || (x==0 && y > 0))
        {
            neg[lefts].first = x;
            neg[lefts].second = y;
            lefts++;
        }
        else
        {
            pos[rights].first = x;
            pos[rights].second = y;
            rights++;
        }
    }

    sort(neg, neg+lefts, leftcomp);
    sort(pos, pos+rights,rightcomp);

    double leftMinCos = 1;
    double rightMinCos = 1;
    pii *lv1;
    pii *lv2;
    for(int i = 1; i < lefts; i++)
    {
        double val = dot(neg[i-1],neg[i])/norm(neg[i-1])/norm(neg[i]);
        if(val < leftMinCos)
        {
            leftMinCos = val;
            lv1 = &neg[i-1];
            lv2 = &neg[i];
        }
    }
    pii *rv1;
    pii *rv2;
    for(int i = 1; i < rights; i++)
    {
        double val = dot(pos[i-1],pos[i])/norm(pos[i-1])/norm(pos[i]);
        if(val < rightMinCos)
        {
            rightMinCos = val;
            rv1 = &pos[i-1];
            rv2 = &pos[i];
        }
    }

    double myMin = 1;
    double m1 = 2,m2 = 2,m3,m4;
    if(lefts && rights)
    {
        myMin = min(myMin, m1=dot(neg[0], pos[rights-1])/norm(neg[0])/norm(pos[rights-1]));
        myMin = min(myMin, m2=dot(pos[0], neg[lefts-1])/norm(pos[0])/norm(neg[lefts-1]));
    }
    else if(rights)
    {
        myMin = min(myMin, m3=dot(pos[0], pos[rights-1])/norm(pos[0])/norm(pos[rights-1]));
    }
    else if(lefts)
    {
        myMin = min(myMin, m4=dot(neg[0], neg[lefts-1])/norm(neg[0])/norm(neg[lefts-1]));
    }

    bool flip = 0;
    if(myMin == leftMinCos)
        flip = 1;
    else if(myMin == rightMinCos)
        flip = 1;
    else if(myMin == m1)
        flip = cross(pos[rights-1],neg[0]) < 0;
    else if(myMin == m2)
        flip = cross(neg[lefts-1], pos[0]) < 0;

    myMin = min(myMin, leftMinCos);
    myMin = min(myMin, rightMinCos);

    if(flip)
    printf("%.10lf\n", 180/acos(-1)*acos(myMin));
    else
    printf("%.10lf\n", 360-180/acos(-1)*acos(myMin));
}
