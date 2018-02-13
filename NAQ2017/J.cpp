#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <limits>
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

void encrypt(char *message) {
    LL nums[100];
    int l = strlen(message);
    for (int i = 0; i < l; i++) {
        if (message[i] == ' ')
            nums[i] = 0;
        else
            nums[i] = message[i]-'a'+1;
    }
    for (int i = 1; i < l; i++) {
        nums[i] += nums[i-1];
    }
    for (int i = 1; i < l; i++) {
        nums[i] %= 27;
        if (nums[i] == 0)
            message[i] = ' ';
        else
            message[i] = nums[i]-1+'a';
    }
}

void decrypt(char *message) {
    LL nums[100];
    int l = strlen(message);
    for (int i = 0; i < l; i++) {
        if (message[i] == ' ')
            nums[i] = 0;
        else
            nums[i] = message[i]-'a'+1;
    }
    for (int i = l-1; i > 0; i--) {
        if(nums[i] < nums[i-1])
            nums[i] += 27;
        nums[i] -= nums[i-1];
    }
    for (int i = 1; i < l; i++) {
        if (nums[i] == 0)
            message[i] = ' ';
        else
            message[i] = nums[i]-1+'a';
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i = 0; i < n; i++) {
        char action;
        char message[100];
        string line;
        getline(cin, line);
        action = line[0];
        strcpy(message, line.c_str()+2);

        if (action == 'e')
            encrypt(message);
        else
            decrypt(message);
            
        cout << message << endl;
    }
}
