n = int(input())
while n >= 0:
    m = 0
    lastt = 0
    for i in range(n):
        s,t = [int(a) for a in input().split()]
        m += s*(t-lastt)
        lastt = t
    print(m, 'miles')
    n = int(input())
