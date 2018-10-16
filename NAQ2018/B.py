p, q, s = [ int(a) for a in input().split() ]
together = False
for i in range(1,s+1):
    if i % p == 0 and i % q == 0:
        together = True

if together:
    print('yes')
else:
    print('no')
