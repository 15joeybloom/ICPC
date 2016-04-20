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
    char arr[105];

    scanf("%s", arr);

    vector<char> vec;
    for(int i = 0; i < strlen(arr); i++)
    {
        vec.push_back(tolower(arr[i]));
    }

    for(int i = 0; i < vec.size(); )
    {
        char c = vec[i];

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
        {
            vec.erase(vec.begin()+i);
        }
        else
        {
            vec.insert(vec.begin()+i, '.');
            i+= 2;
        }
    }

    for(int i = 0; i < vec.size(); i++)
    {
        printf("%c", vec[i]);
    }
    printf("\n");
}
