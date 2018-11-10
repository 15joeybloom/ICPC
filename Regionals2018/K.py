import sys

s = input()
n = len(s)

suffixes = []
for i in range(n-1):
    suffixes.append((i, [ord(s[i]) - ord('a'), ord(s[i+1]) - ord('a')]))
suffixes.append((n-1, [ord(s[-1]) - ord('a'), -1]))

suffixes.sort(key=lambda x: x[1])

k = 2
while k >> 1 < n:
    ind = [0 for _ in range(n)]
    rank = 0
    prevRank = suffixes[0][1][0]
    suffixes[0][1][0] = 0
    ind[suffixes[0][0]] = 0
    for i in range(1, n):
        if prevRank != suffixes[i][1][0] \
                or suffixes[i-1][1][1] != suffixes[i][1][1]:
            rank += 1
        prevRank = suffixes[i][1][0]
        suffixes[i][1][0] = rank
        ind[suffixes[i][0]] = i
    for i in range(n):
        nextIndex = suffixes[i][0]+k
        if nextIndex < n:
            suffixes[i][1][1] = suffixes[ind[nextIndex]][1][0]
        else:
            suffixes[i][1][1] = -1

    suffixes.sort(key=lambda x: x[1])
    k <<= 1

lcp = [ 0 for _ in range(n) ]
currentlcp = 0
for i in range(n):
    if ind[i] == n-1:
        currentlcp = 0
        continue
    j = suffixes[ind[i]+1][0]
    while i+currentlcp<n and s[i+currentlcp]==s[j+currentlcp]:
        currentlcp += 1
    lcp[ind[i]] = currentlcp

    if currentlcp > 0:
        currentlcp -= 1

best = 0
for i in range(n):
    if lcp[i] > lcp[best]:
        best = i

print(s[suffixes[best][0]:suffixes[best][0]+lcp[best]])

