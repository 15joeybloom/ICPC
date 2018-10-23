n = int(input())
l = []
r = []
for _ in range(n):
    x = [ int(a) for a in input().split() ]
    l.append(x[0])
    r.append(x[1])
sort(l)
sort(r)
print(sum([ max(l[i], r[i]) for i in range(n) ]))
