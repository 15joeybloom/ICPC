t = int(input())
for tt in range(t):
    n = int(input())

    x = n*(n+1)//2
    
    i = 0
    while 2**i <= n:
        x -= 2**(i+1)
        i += 1

    print(x)
