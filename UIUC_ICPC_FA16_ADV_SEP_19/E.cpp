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

int key['z'+10];
int times['z'+10];
int main()
{
    //printf("%d %d", ' ', 'a');
    key[' '] = 0; times[' '] = 1;
    key['a'] = 2; times['a'] = 1;
    key['b'] = 2; times['b'] = 2;
    key['c'] = 2; times['c'] = 3;
    key['d'] = 3; times['d'] = 1;
    key['e'] = 3; times['e'] = 2;
    key['f'] = 3; times['f'] = 3;
    key['g'] = 4; times['g'] = 1;
    key['h'] = 4; times['h'] = 2;
    key['i'] = 4; times['i'] = 3;
    key['j'] = 5; times['j'] = 1;
    key['k'] = 5; times['k'] = 2;
    key['l'] = 5; times['l'] = 3;
    key['m'] = 6; times['m'] = 1;
    key['n'] = 6; times['n'] = 2;
    key['o'] = 6; times['o'] = 3;
    key['p'] = 7; times['p'] = 1;
    key['q'] = 7; times['q'] = 2;
    key['r'] = 7; times['r'] = 3;
    key['s'] = 7; times['s'] = 4;
    key['t'] = 8; times['t'] = 1;
    key['u'] = 8; times['u'] = 2;
    key['v'] = 8; times['v'] = 3;
    key['w'] = 9; times['w'] = 1;
    key['x'] = 9; times['x'] = 2;
    key['y'] = 9; times['y'] = 3;
    key['z'] = 9; times['z'] = 4;

    char *message = NULL;
    size_t message_size = 0;
    int N;
    getline(&message, &message_size, stdin);
    sscanf(message, "%d", &N);

    for(int t = 1; t <= N; t++)
    {
        printf("Case #%d: ", t);
        getline(&message, &message_size, stdin);

        int previous = 10;
        for(int i = 0; i < strlen(message); i++)
        {
            if(key[message[i]] == previous)
                printf(" ");
            for(int j = 0; j < times[message[i]]; j++)
                printf("%d", key[message[i]]);

            previous = key[message[i]];
        }
        printf("\n");
    }
}
