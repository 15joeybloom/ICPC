#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct suffix {
    LL start;
    LL rank0;
    LL rank1;

    bool operator<(const suffix &other) const {
        if (rank0 == other.rank0)
            return rank1 < other.rank1;
        return rank0 < other.rank0;
    }
} suffixes[100010];
LL startingAt[100010];
LL n;
LL lcp[100010];
char s[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n-1; i++) {
        suffixes[i].start = i;
        suffixes[i].rank0 = s[i]-'a';
        suffixes[i].rank1 = s[i+1]-'a';
    }
    suffixes[n-1].start = n-1;
    suffixes[n-1].rank0 = s[n-1]-'a';
    suffixes[n-1].rank1 = -1;

    sort(suffixes, suffixes+n);

    for (LL k = 2; k >> 1 < n; k <<= 1) {
        memset(startingAt, 0, sizeof(startingAt));
        LL rank = 0;
        LL prevRank = suffixes[0].rank0;
        suffixes[0].rank0 = 0;
        for (int i = 1; i < n; i++) {
            if (prevRank != suffixes[i].rank0 
                    || suffixes[i-1].rank1 != suffixes[i].rank1)
                rank++;
            prevRank = suffixes[i].rank0;
            suffixes[i].rank0 = rank;
            startingAt[suffixes[i].start] = i;
        }
        for (int i = 0; i < n; i++) {
            LL nextIndex = suffixes[i].start + k;
            if (nextIndex < n)
                suffixes[i].rank1 = suffixes[startingAt[nextIndex]].rank0;
            else
                suffixes[i].rank1 = -1;
        }
        sort(suffixes, suffixes+n);
    }

    memset(lcp, 0, sizeof(lcp));
    LL currentlcp = 0;
    for (int i = 0; i < n; i++) {
        if (startingAt[i] == n-1) {
            currentlcp = 0;
            continue;
        }
        LL j = suffixes[startingAt[i]+1].start;
        while (i + currentlcp < n && s[i+currentlcp] == s[j+currentlcp])
            currentlcp++;
        lcp[startingAt[i]] = currentlcp;

        if (currentlcp > 0)
            currentlcp--;
    }

    LL best = 0;
    for (int i = 0; i < n; i++) {
        if (lcp[i] > lcp[best])
            best = i;
    }

    s[suffixes[best].start+lcp[best]] = '\0';
    printf("%s\n", s+suffixes[best].start);
}
