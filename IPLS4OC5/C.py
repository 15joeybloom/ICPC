T = int(input())
for t in range(1, T+1):
    a, b, c = [ int(x) for x in input().split() ]
    if a <= 0 or b <= 0 or c <= 0 \
            or a + b <= c or b + c <= a or c + a <= b:
        status = 'Invalid'
    elif a == b and b == c:
        status = 'Equilateral'
    elif a == b or b == c or c == a:
        status = 'Isosceles'
    else:
        status = 'Scalene'
    print('Case {0}: {1}'.format(t, status))

