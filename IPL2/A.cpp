#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>
using namespace std;

int main()
{
    char word[110];
    char newword[110];

    scanf("%s", word);

    int i;
    for(i = 1; i < strlen(word); i++) {
        if(isupper(word[i])) {
            newword[i] = tolower(word[i]);
        }
        else {
            printf("%s\n", word);
            return 0;
        }
    }

    newword[0] = isupper(word[0]) ? tolower(word[0]) : toupper(word[0]);
    newword[strlen(word)] = 0;
    printf("%s\n", newword);
    return 0;
}
