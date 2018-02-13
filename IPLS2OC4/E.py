import heapq
n, m, s = [int(a) for a in input().split()]
s -= 1

adj = [[] for _ in range(n)]
for _ in range(m):
    v,u,w = [int(a) for a in input().split()]
    v -= 1
    u -= 1
    adj[u].append((w,v))
    adj[v].append((w,u))
l = int(input())

infinity = 1000*10**5*10
dist = [infinity] * n
pq = []

heapq.heappush(pq, (0,s))
while pq:
    d,i = heapq.heappop(pq)
    if d > l:
        break
    if dist[i] == infinity:
        dist[i] = d
        for w,j in adj[i]:
            heapq.heappush(pq, (d+w,j))

print(dist)

counter = len([i for i in range(n) if dist[i] == l]) 
for i in range(n):
    for w,j in adj[i]:
        if i > j:
            continue

        if dist[i] < l and l - dist[i] < w and w - (l - dist[i]) + dist[j] > l:
            counter += 1
        if dist[j] < l and l - dist[j] < w and w - (l - dist[j]) + dist[i] > l:
            counter += 1
        if dist[j] < l and dist[i] < l and dist[i] + dist[j] + w == 2 * l:
            counter += 1
    '''
        continue
        if dist[i] > l and dist[j] > l:
            continue
        if i + w == dist[j]:
            if dist[i] < l < dist[j]:
                counter += 1
        elif j + w == dist[i]:
            if dist[j] < l < dist[i]:
                counter += 1
        else:
            mid = (dist[i]+dist[j]+w)/2
            if mid == l and mid != dist[i] and mid != dist[j]:
                counter += 1
            else:
                if dist[i] < l < mid:
                    counter += 1
                if dist[j] < l < mid:
                    counter += 1
                    '''
print(counter)
