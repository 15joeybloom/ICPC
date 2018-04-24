p,q,l,r = [ int(a) for a in input().split() ]
a = []
b = []
c = []
d = []
for i in range(p):
    aa,bb = [ int(a) for a in input().split() ]
    a.append(aa)
    b.append(bb)
for i in range(q):
    aa,bb = [ int(a) for a in input().split() ]
    c.append(aa)
    d.append(bb)

#print(p,q,l,r)
#print(a,b,c,d)
counter = 0
for i in range(l,r+1):
    j = k = 0
    while j < p and k < q:
        if b[j] < c[k] + i:
            j += 1
        elif d[k] + i < a[j]:
            k += 1
        else:
            counter += 1
            break

print(counter)
