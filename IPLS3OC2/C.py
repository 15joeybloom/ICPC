n = int(input())

board = [['.' for _ in range(n)] for _ in range(n)]

count = 0
for i in range(n):
    for j in range(n):
        if (i+j)%2 == 0:
            board[i][j] = 'C'
            count += 1

print(count)
for i in range(n):
    print(''.join(board[i]))
