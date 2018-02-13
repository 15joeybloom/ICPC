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
  int X;
  cin >> X;

  int i;
  for (i = 1; X > 0; i++) {
    X -= i;
  }

  cout << i-1 << endl;
}
