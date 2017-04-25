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

int main()
{
  int a,b,c;
  scanf("%d %d %d", &a, &b, &c);

  int best = 0;
  best = max(best,a+b+c);
  best = max(best,a*b+c);
  best = max(best,a+b*c);
  best = max(best,a*b*c);
  best = max(best,(a+b)*c);
  best = max(best,a*(b+c));

  printf("%d\n", best);
}
