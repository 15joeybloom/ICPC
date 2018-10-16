m, n = [ int(a) for a in input().split() ]
while m != 0:
    grid = ['*'*(n+2)] 
    for _ in range(m):
        grid.append('*' + input() + '*')
    grid.append('*'*(n+2))

    visited = [ [ False for _ in range(n+2) ] for _ in range(m+2) ]
    components = 0
    for i in range(1, m+1):
        for j in range(1, n+1):
            if grid[i][j] == '@' and not visited[i][j]:
                stk = [(i,j)]
                while stk:
                    x, y = stk.pop()
                    if visited[x][y]:
                        continue
                    visited[x][y] = True
                    for dx, dy in [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]:
                        if grid[x+dx][y+dy] == '@':
                            stk.append((x+dx, y+dy))

                components += 1
    print(components)

    m, n = [ int(a) for a in input().split() ]

