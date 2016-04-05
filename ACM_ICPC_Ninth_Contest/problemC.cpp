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
    int n;
    scanf("%d", &n);

    int arr[102];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int bribes = 0;
    while(true)
    {
        int maxCand = 1;
        int maxVotes = arr[1];

        for(int i = 2; i < n; i++)
        {
            if(arr[i] > maxVotes)
            {
                maxCand = i;
                maxVotes = arr[i];
            }
        }
        
        if(arr[maxCand] < arr[0]) break;
        arr[maxCand]--;
        arr[0]++;
        bribes++;
    }

    cout << bribes << endl;
}
