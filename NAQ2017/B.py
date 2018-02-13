import heapq
n, m, f, s, t = [int(a) for a in input().split()]

infinity = 50000*50000*10
adj = [[] for _ in range(2*n)]
dist = [infinity for _ in range(2*n)]

adj[t].append((0,t+n))
#for i in range(n):
#    adj[i].append((0,i,i+n))

for _ in range(m):
    i, j, c = [int(a) for a in input().split()]
    adj[i].append((c,j))
    adj[j].append((c,i))
    adj[i+n].append((c,j+n))
    adj[j+n].append((c,i+n))

for _ in range(f):
    u, v = [int(a) for a in input().split()]
    adj[u].append((0,v+n))

dist[s] = 0
heap = list(adj[s])
heapq.heapify(heap)
while dist[t+n] == infinity:
    d, j = heapq.heappop(heap)
    if dist[j] == infinity:
        dist[j] = d
        for c,k in adj[j]:
            heapq.heappush(heap, (d+c,k))

print(dist[t+n])
