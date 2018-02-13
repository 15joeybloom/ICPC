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
#include <cctype>
using namespace std;

int main()
{
    char *buffer = NULL;
    size_t buffersize = 0;
    int bytes = 0;

    while((bytes = getline(&buffer, &buffersize, stdin)) >= 0)
    {
        for(int i = 0; i < bytes; i++)
        {
            buffer[i] = tolower(buffer[i]);
        }

        if(strstr(buffer, "problem"))
        {
            printf("yes\n");
        }
        else
            printf("no\n");
    }
}

