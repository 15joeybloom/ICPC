#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

vector<char> zerosandtwos;
LL ones;
char s[100010];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s;
    int n = strlen(s);
    ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            zerosandtwos.push_back(s[i]);
        }
    }

    int j = 0;
    while (j < zerosandtwos.size() && zerosandtwos[j] == '0') {
        printf("0");
        j++;
    }
    for (int i = 0; i < ones; i++)
        printf("1");
    for (; j < zerosandtwos.size(); j++)
        printf("%c", zerosandtwos[j]);
    printf("\n");
}
