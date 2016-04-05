#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;


int n;
int loc[25];
vector<int> world[25];

void popTil(int b)
{
    while(world[loc[b]].back() != b)
    {
        int popped = world[loc[b]].back();
        world[loc[b]].pop_back();
        loc[popped] = popped;
        world[popped].push_back(popped);
    }
}
void pile(int a, int b)
{
    vector<int>::iterator it;
    for(it = world[loc[a]].begin(); *it != a; it++)
    ;
    vector<int> *eraseMe = &world[loc[a]];
    vector<int>::iterator eraseStart = it;
    vector<int>::iterator eraseEnd = world[loc[a]].end();
    for(; it != eraseEnd; it++)
    {
        world[loc[b]].push_back(*it);
        loc[*it] = loc[b];
    }
    eraseMe->erase(eraseStart,eraseEnd);
}
void printWorld()
{
    for(int i = 0; i < n; i++)
    {
        printf("%d:",i);
        for(vector<int>::iterator it = world[i].begin(); it != world[i].end(); it++)
        {
            printf(" %d", *it);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++)
    {
        loc[i] = i;
        world[i].push_back(i);
    }

    char first[10], second[10];
    int a, b;
    while(scanf("%s %d %s %d", first, &a, second, &b) != EOF)
    {
        if(a == b || loc[a] == loc[b]) continue;

        string one(first), two(second);
        if(one == "move") popTil(a);
        if(two == "onto") popTil(b);

        pile(a,b);
    }

    printWorld();
}
