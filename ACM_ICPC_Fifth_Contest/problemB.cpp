#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
int main()
{
    int n, k;
    while(scanf("%d %d",&n,&k)!=EOF && n > 0)
    {
        Node *one = new Node;
        one->data = 1;
        Node *curr = one;
        for(int i = 2; i <=n; i++)
        {
            curr->next = new Node;
            curr->next->data = i;
            curr = curr->next;
        }
        curr->next = one;

        Node *prev = curr;
        curr = one;
        while(curr->next != curr)
        {
            for(int i = 1; i < k; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            Node *deleteMe = curr;
            prev->next = curr->next;
            delete deleteMe;

            curr = prev->next;
            Node *insertAfter = prev;
            for(int i = 1; i < k; i++)
            {
                prev = curr;
                curr=curr->next;
            }
            Node *moveMe = curr;

            if(insertAfter != moveMe)
            {
            prev->next = curr->next;
            moveMe->next = insertAfter->next;
            insertAfter->next = moveMe;
            }
            prev = moveMe;
            curr = moveMe->next;

        }
        int printMe = (2-curr->data+n)%n;
        printf("%d\n",printMe==0?n:printMe);
    }

}
