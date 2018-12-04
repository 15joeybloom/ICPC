n, k = [ int(a) for a in input().split() ]
f = [ int(a) for a in input().split() ]

f.sort()

time = 0
while len(f) > 0:
    time += 2*(f[-1]-1)
    f = f[:-k]

print(time)
