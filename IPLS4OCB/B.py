s, x1, x2 = [ int(a) for a in input().split() ]
t1, t2 = [ int(a) for a in input().split() ]
p, d = [ int(a) for a in input().split() ]

if p < x1 and d == -1:
    t = p * t1
    p = 0
    d = 1
elif x1 < p and d == 1:
    t = (s-p) * t1
    p = s
    d = -1
else:
    t = 0
t += t1 * abs(p-x1)
p = x1
if p < x2 and d == -1:
    t += p * t1
    p = 0
    d = 1
elif x2 < p and d == 1:
    t += (s-p) * t1
    p = s
    d = -1
t += t1 * abs(p-x2)
p = x2

igor = t2 * abs(x1-x2)

print(min(t,igor))
