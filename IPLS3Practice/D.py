n,m = [int(a) for a in input().split()]
if 2*n+2 < m or m+1 < n:
    print(-1)
else:
    output = ''
    if m < n:
        n -= 1
        output += '0'

    while m > 1 and n > 0:
        if m == n:
            output += '10' * m
            m = 0
            n = 0
        else:
            output += '110'
            m -= 2
            n -= 1
    output += '1' * m
    output += '0' * n

    print(output)
