#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//a heap that preserves inorder traversal order
struct Treap 
{
    int priority, sortVal;
    //left and right children
    Treap *left, *right;
    //number of nodes in this tree, including root
    int size;

    Treap(int i) : sortVal(i), left(NULL), right(NULL) 
    {
        priority = rand() % INT_MAX;
    }
};

void printTreap(Treap *t, int level)
{
    for(int i = 0; i < level; i++)
        printf("  ");
    if(t == NULL)
        printf("NULL\n");
    else
    {
        printf("Priority: %d, Val: %d, Size: %d\n", t->priority, t->sortVal, t->size);

        printTreap(t->left, level+1);
        printTreap(t->right, level+1);
    }
}

void updateSize(Treap *t)
{
    t->size = 1;
    if(t->left)
        t->size += t->left->size;
    if(t->right)
        t->size += t->right->size;
}

void rotateLeft(Treap *&t)
{
    Treap *temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t = temp;

    updateSize(t->left);
    updateSize(t);
}

void rotateRight(Treap *&t)
{
    Treap *temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t = temp;

    updateSize(t->right);
    updateSize(t);
}

void heapifyDown(Treap *&t)
{
    if(t == NULL)
        return;

    int leftPriority = t->left ? t->left->priority : INT_MIN; 
    int rightPriority = t->right ? t->right->priority : INT_MIN;
    if(leftPriority > t->priority && leftPriority > rightPriority)
    {
        rotateRight(t);
        heapifyDown(t->right);
    }
    else if(rightPriority > t->priority)
    {
        rotateLeft(t);
        heapifyDown(t->left);
    }
}
void insert(Treap *&t, int id)
{
    //for this problem, we always insert at the left.
    if(t == NULL)
        t = new Treap(id);
    else
    {
        insert(t->left,id);
        if(t->left->priority > t->priority)
            rotateRight(t);
    }

    updateSize(t);
}

//returns the number of movies above the one we remove
void remove(Treap *&t, int target, int &count)
{
    if(t->sortVal == target)
    {
        if(t->left)
        {
            count += t->left->size;
            if(t->right)//two children
            {
                Treap *ios = t->right;
                while(ios->left) 
                    ios=ios->left;
                int tempPriority = t->priority;
                int tempSortVal = t->sortVal;
                t->priority = ios->priority;
                t->sortVal = ios->sortVal;
                ios->priority = tempPriority;
                ios->sortVal = tempSortVal;
                remove(t->right, target, count);
                heapifyDown(t);
            }
            else //only a left child
            {
                Treap *deleteMe = t;
                t = t->left;
                delete deleteMe;
                return;
            }
        }
        else if(t->right) //only a right child
        {
            Treap *deleteMe = t;
            t = t->right;
            delete deleteMe;
            return;
        }
        else //no children
        {
            delete t;
            t = NULL;
            return;
        }
    }
    else if(target < t->sortVal)
        remove(t->left, target, count);
    else
    {
        count += 1;
        if(t->left)
            count += t->left->size;
        remove(t->right, target, count);
    }

    updateSize(t);
}

void clear(Treap *t)
{
    if(t == NULL)
        return;

    clear(t->left);
    clear(t->right);
    delete t;
}

#define MAXN 100003
int alias[MAXN];
int main()
{
    srand(271828182);

    int T = 0;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        Treap *root = NULL;
        //gotta go backwards here because
        //my lame treap insertion expects
        //inserting in that order
        for(int i = n; i >= 1; i--)
        {
            alias[i] = i;
            insert(root, i);
        }

        bool first = true;
        for(int i = 0; i > -m; i--)
        {
            int a;
            scanf("%d", &a);
            int count = 0;
            remove(root, alias[a], count); 
            if(first)
                printf("%d", count);
            else
                printf(" %d", count);

            alias[a] = i;
            insert(root, i);
            first = false;
        }
        printf("\n");
        clear(root);
    }
}

//brute-force solution below. too slow; O(n^2)
/*
int a[100000];
int n, m;
int main()
{
    int T = 0;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
        {
            a[i] = i+1;
        }

        for(int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);

            int i;
            for(i = 0; a[i]!=x; i++);

            printf("%d ", i);

            while(i > 0)
            {
                a[i] = a[i-1];
                i--;
            }
            a[0] = x;
        }

        printf("\n");
    }
}
*/
