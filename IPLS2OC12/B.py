n = int(input())
tups = []
for i in range(n):
    ai,bi = [int(x) for x in input().split()]
    tups.append((ai,bi))

tups.sort(key=lambda x:x[0])
good = True
for i in range(n-1):
    _,b0 = tups[i]
    _,b1 = tups[i+1]
    if b0 > b1:
        good = False

if good:
    print('Poor Alex')
else:
    print('Happy Alex')

