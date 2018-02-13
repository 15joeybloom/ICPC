n = int(input())
grid = []
for i in range(n):
    grid.append(input())

diag = grid[0][0]
other = grid[0][1]

good = True
for i in range(n):
    for j in range(n):
        if i == j or i+j == n-1:
            if grid[i][j] != diag:
                good = False
        elif grid[i][j] != other:
            good = False
if diag != other and good:
    print("YES")
else:
    print("NO")
