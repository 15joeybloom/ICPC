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

int a[100010];
map<int, int> first;
map<int, int> last;
map<int, int> freq;
int main()
{
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }

  for(int i = 0; i < n; i++) {
    if(freq.count(a[i])) {
      last[a[i]] = i;
      freq[a[i]]++;
    }
    else {
      first[a[i]] = i;
      last[a[i]] = i;
      freq[a[i]] = 1;
    }
  }
  
  int beauty = 0;
  int start = 0;
  int finish = n;
  map<int,int>::iterator it;
  for(it = freq.begin(); it != freq.end(); it++) {
    beauty = max(beauty, it->second);
  }
  for(it = freq.begin(); it != freq.end(); it++) {
    if(it->second == beauty) {
      if(last[it->first]-first[it->first] < finish-start) {
        start = first[it->first];
        finish = last[it->first];
      }
    }
  }

  printf("%d %d\n", start+1, finish+1);
}
