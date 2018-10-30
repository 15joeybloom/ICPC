l, r = [ int(a) for a in input().split() ]
print('YES')
for i in range(l, r, 2):
    print(i, i+1)
