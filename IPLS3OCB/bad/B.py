a,m = [ int(a) for a in input().split() ]

visited = [False]*m

while True:
    visited[a%m] = True
    a = (2 * a) % m
    if a == 0:
        print('Yes')
        break
    elif visited[a%m]:
        print('No')
        break
