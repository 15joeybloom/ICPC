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
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        char word[101];

        cin >> word;

        int len = strlen(word);
        if(len > 10)
        {
            cout << word[0];
            cout << len-2;
            cout << word[len-1];
        }
        else cout << word;

        cout << endl;
    }

}
