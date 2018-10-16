import heapq

h, w = [ int(a) for a in input().split() ]
alt = [[0 for _ in range(w+2)]]
for _ in range(h):
    alt.append([0] + [ int(a) for a in input().split() ] + [0])
alt.append([0 for _ in range(w+2)])
i, j = [ int(a) for a in input().split() ]

for a in range(len(alt)):
    for b in range(len(alt[a])):
        if alt[a][b] > 0:
            alt[a][b] = 0

directions = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]
q = [(alt[i][j], i, j)]
visited = [[alt[a][b] >= 0 for b in range(w+2)] for a in range(h+2)]
while q:
    a, x, y = heapq.heappop(q)
    if visited[x][y]:
        continue

    visited[x][y] = True
    alt[x][y] = a
    for a, b in directions:
        newx = x + a
        newy = y + b
        if not visited[newx][newy]:
            heapq.heappush(q, (max(alt[newx][newy], alt[x][y]), newx, newy))

#for a in alt:
    #print(a)

total = 0
for a in range(1, h+1):
    for b in range(1, w+1):
        if visited[a][b]:
            total += alt[a][b]

print(-total)
