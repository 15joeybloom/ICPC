N = int(input())

ts = [0]
xs = [0]
ys = [0]

for _ in range(N):
    t,x,y = [ int(a) for a in input().split() ]
    ts.append(t)
    xs.append(x)
    ys.append(y)

good = True
for i in range(N):

    dist = abs(xs[i]-xs[i+1])+abs(ys[i]-ys[i+1]) 
    time = ts[i+1]-ts[i]
    # Parity
    if dist%2 != time%2:
        good = False

    # Distance
    if dist > time:
        good = False

if good:
    print('Yes')
else:
    print('No')

