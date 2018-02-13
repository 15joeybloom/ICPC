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

char s[200020];
int main()
{
  scanf("%s", s);

  int firsta = 200000000;
  int lastz = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'A')
      firsta = min(firsta, i);
    else if (s[i] == 'Z')
      lastz = max(lastz, i);
  }

  printf("%d\n", lastz-firsta+1);
}
