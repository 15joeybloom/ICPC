N, M = [int(a) for a in input().split()]
adj = [[False] * N for _ in range(N)]
edgelist = []
for i in range(M):
    a, b = [int(a) for a in input().split()]
    a-=1
    b-=1
    adj[a][b] = True
    adj[b][a] = True
    edgelist.append((a,b))

bridges = 0
for a,b in edgelist:
    adj[a][b] = False
    adj[b][a] = False

    marked = [False] * N
    stk = [a]
    while stk:
        x = stk.pop()
        marked[x] = True
        for i in range(N):
            if adj[x][i] and not marked[i]:
                stk.append(i)
    if not marked[b]:
        bridges += 1

    adj[a][b] = True
    adj[b][a] = True

print(bridges)
