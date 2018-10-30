n = int(input())
whowins = [ 0 for _ in range(n) ]
adj = [ set() for _ in range(n+1) ]
p = [ int(a) for a in input().split() ]

for i in range(1, n+1):
    for j in range(i+p[i], n+1, p[i]):
        adj[j].append(p)
    for j in range(i-p[i], 0, -p[i]):
        adj[j].append(p)

ready = [ i for i in range(1, n+1) if adj[i] == set() ]
while ready:

