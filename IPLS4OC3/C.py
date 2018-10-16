choose = [ [ 0 for _ in range(50) ] for _ in range(50) ]
for i in range(50):
    choose[i][0] = 1
for i in range(1,50):
    for j in range(1, i+1):
        choose[i][j] = choose[i-1][j-1] + choose[i-1][j]

T = int(input())
for t in range(T):
    n = int(input())
    p = float(input())
    result = 0
    for i in range(n, 2*n):
        result += choose[2*n-1][i]*p**i*(1-p)**(2*n-1-i)
    print('{0:.2f}'.format(result))

