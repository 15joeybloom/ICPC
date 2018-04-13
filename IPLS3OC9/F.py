n,a,b = [ int(a) for a in input().split() ]
p = [ int(a) for a in input().split() ]

s = set(p)
haspartnera = [ a-x in s for x in p ]
haspartnerb = [ b-x in s for x in p ]

bad = False
for i in range(n):
    if not haspartnera[i] and not haspartnerb[i]:
        bad = True

if bad:
    print('NO')
else:
    print('YES')
    
