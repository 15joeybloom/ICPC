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

typedef struct Event{
    int x;
    int otherX; int y1; int y2;
    bool left;
} Event;

bool compx(const Event& e1, const Event& e2)
{
    return e1.x < e2.x;
}
bool compy(const pair<int,int>& p1, const pair<int, int>& p2)
{
    return p1.first < p2.first;
}
Event events[10010];
int n;
int solve()
{
    sort(events, events+2*n, compx);

    multiset<pair<int,int>, bool (*)(const pair<int,int>&, const pair<int,int>&)> actives(&compy);

    int currentX = -10000;
    int perimeter = 0;
    for(int i = 0; i < 2*n; i++)
    {
        int count = 0;
        int lastright = -10001;
        multiset<pair<int,int>, bool(*)(const pair<int,int>&, const pair<int,int>&)>::iterator it;
        for(it = actives.begin(); it != actives.end(); ++it)
        {
            if(lastright < it->first)
                count++;
            lastright = max(lastright, it->second);
        }

        perimeter += 2*count*(events[i].x-currentX);

        currentX = events[i].x;

        if(events[i].left)
            actives.insert(make_pair(events[i].y1, events[i].y2));
        else
            actives.erase(actives.find(make_pair(events[i].y1, events[i].y2)));
    }

    return perimeter;
}
int main()
{
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        events[2*i].x = events[2*i+1].otherX = x1;
        events[2*i].otherX = events[2*i+1].x = x2;
        events[2*i].left = true;
        events[2*i+1].left = false;
        events[2*i].y1 = events[2*i+1].y1 = y1;
        events[2*i].y2 = events[2*i+1].y2 = y2;
    }

    int perimeter = solve();
    for(int i = 0; i < 2*n; i++)
    {
        if(events[i].left)
        {
            swap(events[i].y1, events[i].x);
            swap(events[i].y2, events[i].otherX);
        }
        else
        {
            swap(events[i].y1, events[i].otherX);
            swap(events[i].y2, events[i].x);
        }
    }
    perimeter += solve();

    printf("%d\n", perimeter);
}
