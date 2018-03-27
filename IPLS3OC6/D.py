N,K = [ int(a) for a in input().split() ]

MOD = 2*K

desires = [ [0]*MOD for _ in range(MOD) ]

for _ in range(N):
    toks = input().split()
    x = int(toks[0])
    y = int(toks[1])
    c = toks[2]
    if c == 'B':
        desires[x%MOD][y%MOD] += 1
    else:
        desires[x%MOD][(y+K)%MOD] += 1

rows = [ [0]*MOD for _ in range(MOD) ]
squares = [ [0]*MOD for _ in range(MOD) ]

for i in range(MOD):
    rows[i][0] = sum(desires[i][0:K])

for i in range(MOD):
    for j in range(1,MOD):
        rows[i][j] = rows[i][j-1] + desires[i][j-K-1] - desires[i][j-1]

for j in range(MOD):
    squares[0][j] = sum([rows[i%MOD][j] for i in range(K) ])

for i in range(1,MOD):
    for j in range(MOD):
        squares[i][j] = squares[i-1][j] + rows[i-K-1][j] - rows[i-1][j]

best = 0
for i in range(K):
    for j in range(K):
        best = max(best, squares[i][j]+squares[i+K][j+K])
print(best)
