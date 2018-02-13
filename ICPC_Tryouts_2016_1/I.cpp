#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <regex>

using namespace std;

char input[110][110];
int main()
{
    char P[110];
    scanf("%s", P);

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", input[i]);
    }

    string pattStr(P);
    string escaper("\\*");
    regex e(escaper, regex_constants::grep);
    string rep("\\$1");
    string escapedPattStr = regex_replace(pattStr, e, rep);

    printf("%s", escapedPattStr.c_str());

    return 0;

    bool lead = P[0] == '*';
    bool trail = P[strlen(P)-1] == '*';

    vector<char*> words;
    if(!lead) words.push_back(P);

    char *ptr = P+1;
    while((ptr=strchr(P, '*')))
    {
        *ptr = 0;
        ptr++;
        words.push_back(ptr);
    }

    for(int i = 0; i < N; i++)
    {
        if(!lead && strncmp(words[0],P, 1) )
        {
        }
    }
}
