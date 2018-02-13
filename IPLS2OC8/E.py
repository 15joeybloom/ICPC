#!/usr/bin/python3

n,m,K = [int(a) for a in input().split()]

adj = [[] for _ in range(n)]
for i in range(m):
    a,b = [int(a) for a in input().split()]
    adj[a-1].append(b-1)

reach = [[False] * n for _ in range(n)]
for i in range(n):
    reach[i][i] = True
for i in range(n):
    for j in adj[i]:
        reach[i][j] = True

for k in range(n):
    for i in range(n):
        for j in range(n):
            if reach[i][k] and reach[k][j]:
                reach[i][j] = True

minreach = n**3 
for i in range(n):
    minreach = min(minreach, reach[i].count(True))

print(minreach * K)
