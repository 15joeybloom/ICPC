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

bool minHeapComp(const LL a, const LL b)
{
    return a < b;
}
bool maxHeapComp(const LL a, const LL b)
{
    return a > b;
}
struct Heap
{
    LL data[31000];
    int size = 0;
    bool (*comp)(const LL, const LL);

    void heapify_up(int i)
    {
        if(i <= 1)
            return;
        if(comp(data[i],data[i/2]))
        {
            swap(data[i], data[i/2]);
            heapify_up(i/2);
        }
    }
    void heapify_down(int i)
    {
        bool leftch = 2*i <= size && !comp(data[i],data[2*i]);
        bool rightch = 2*i+1 <= size && !comp(data[i],data[2*i+1]);
        if(leftch && rightch)
        {
            if(comp(data[2*i],data[2*i+1]))
            {
                swap(data[i], data[2*i]);
                heapify_down(2*i);
            }
            else
            {
                swap(data[i], data[2*i+1]);
                heapify_down(2*i+1);
            }
        }
        else if(leftch)
        {
            swap(data[i], data[2*i]);
            heapify_down(2*i);
        }
        else if(rightch)
        {
            swap(data[i], data[2*i+1]);
            heapify_down(2*i+1);
        }
    }
    void add(LL x)
    {
        data[++size] = x;
        heapify_up(size-1);
    }
    LL peek()
    {
        return data[1];
    }
    LL remove()
    {
        LL returnMe = data[1];
        data[1] = data[size];
        size--;
        heapify_down(1);
        return returnMe;
    }
} leftHeap, rightHeap;

LL adds[31000];
LL getss[31000];
int main()
{
    leftHeap.comp = maxHeapComp;
    rightHeap.comp = minHeapComp;

    int nadds, ngetss;
    scanf("%d %d", &nadds, &ngetss);

    for(int i = 0; i < nadds; i++)
    {
        scanf("%lld", adds+i);
    }
    for(int i = 0; i < ngetss; i++)
        scanf("%lld", getss+i);

    LL *getssptr = getss;
    for(int i = 0; i < nadds; i++)
    {
        if(leftHeap.size > 0 && adds[i] < leftHeap.peek())
        {
            leftHeap.add(adds[i]);
            rightHeap.add(leftHeap.remove());
        }
        else
        {
            rightHeap.add(adds[i]);
        }

        while(i+1 == *getssptr && (getssptr-getss) < ngetss)
        {
            printf("%I64d\n", rightHeap.peek());
            leftHeap.add(rightHeap.remove());
            getssptr++;
        }
    }
}
