n = int(input())
board = ['x'*(n+2)]+['x'+input()+'x' for _ in range(n)]+['x'*(n+2)]

good = True
for i in range(1,n+1):
    for j in range(1,n+1):
        oneighbors = 0
        if board[i-1][j] == 'o':
            oneighbors += 1
        if board[i+1][j] == 'o':
            oneighbors += 1
        if board[i][j-1] == 'o':
            oneighbors += 1
        if board[i][j+1] == 'o':
            oneighbors += 1
        if (oneighbors % 2) == 1:
            good = False

if good:
    print('YES')
else:
    print('NO')

