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

typedef long long LL;

LL roadcomp[200020];
LL railcomp[200020];

map<LL, LL> freqs; 

LL roadfind(LL i) {
  if (roadcomp[i] == i)
    return i;
  return roadcomp[i] = roadfind(roadcomp[i]);
}
LL railfind(LL i) {
  if (railcomp[i] == i)
    return i;
  return railcomp[i] = railfind(railcomp[i]);
}

int main()
{
  LL N, K, L;
  scanf("%lld %lld %lld", &N, &K, &L);

  for (LL i = 1; i <= N; i++) {
    roadcomp[i] = railcomp[i] = i;
  }
  for (LL i = 0; i < K; i++) {
    LL p, q;
    scanf("%lld %lld", &p, &q);
    roadcomp[roadfind(q)] = roadfind(p);
  }

  for (LL i = 0; i < L; i++) {
    LL p, q;
    scanf("%lld %lld", &p, &q);
    railcomp[railfind(q)] = railfind(p);
  }

  for (LL i = 1; i <= N; i++) {
    LL prod = railfind(i)*200001+roadfind(i);
    freqs[prod]++;
  }
  /*
  for (LL i = 1; i <= N; i++) {
    printf("%lld %lld\n", railcomp[i], roadcomp[i]);
  }
  */
  for (LL i = 1; i <= N; i++) {
    LL prod = railfind(i)*200001+roadfind(i);
    printf("%lld", freqs[prod]);
    if (i == N)
      printf("\n");
    else
      printf(" ");
  }

  return 0;
}
