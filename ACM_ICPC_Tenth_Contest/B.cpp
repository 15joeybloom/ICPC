#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void add(vector<long long> &res, const vector<long long> &a, const vector<long long> &b)
{
    int i = 0;
    long long carry = 0;
    while(i < a.size() && i < b.size())
    {
        res.push_back(a[i]+b[i]+carry);
        if(res[i] > 9999999999999999LL)
        {
            res[i] -= 10000000000000000LL;
            carry = 1;
        }
        else carry = 0;

        i++;
    }
    if(i < a.size())
    {
        res.push_back(a[i]+carry);
    }
    else if(i < b.size())
        res.push_back(b[i]+carry);
    else if(carry)
        res.push_back(carry);
}
int main()
{
    int N;
    cin >> N;
    
    vector<long long> a, b, r;
    vector<long long> *aa = &a, *bb = &b, *res = &r, *temp;
    a.push_back(0LL);
    b.push_back(1LL);
    add(r,a,b);
    for(int i = 1; i <= N; i++)
    {
        temp = aa;
        aa = bb;
        bb = res;
        res = temp;
        res->clear();
        add(*res,*aa,*bb);
    }

    printf("%lld",res->back());
    for(int i = res->size()-2; i >= 0; i--)
    {
        printf("%016lld",(*res)[i]);
    }
    cout << endl;
}
