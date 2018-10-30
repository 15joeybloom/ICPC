// Author: John Qian

#include <vector>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct flight {
  int from;
  int to;
  int dep;
  int arr;

  bool operator<(const flight &other) const {
      return arr < other.arr;
  }
} flight;

flight flights[200010];
vector<int> outfrom[200010];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    memset(flights, 0, sizeof(flights));
    int f, t, d, a;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &flights[i].from, &flights[i].to, &flights[i].dep, &flights[i].arr);
    }

    sort(flights, flights+m);

    for (int i = 0; i < m; i++) {
      outfrom[flights[i].from].push_back(i);
    }

    printf("%d\n", flights[0].from);
    printf("%d\n", outfrom[0][0]);
}
