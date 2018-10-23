n = int(input())
l = []
r = []
for _ in range(n):
    x = [ int(a) for a in input().split() ]
    l.append(x[0])
    r.append(x[1])
l.sort()
r.sort()
print(n + sum([ max(l[i], r[i]) for i in range(n) ]))
