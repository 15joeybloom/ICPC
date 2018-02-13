import sys

n, m, r = [int(a) for a in input().split()]

candles = []
for _ in range(n):
    x,y = [int(a) for a in input().split()]
    candles.append((x,y))

cuts = []
for _ in range(m):
    a,b,c = [int(a) for a in input().split()]
    cuts.append((a,b,c))

for i,(x1,y1) in enumerate(candles):
    for x2,y2 in candles[:i]:
        #print('candle 1:',x1,y1)
        #print('candle 2:',x2,y2)
        good = False
        for a,b,c in cuts:
            #print('cut:',a,b,c)
            #print(a,'*',x1,'+',b,'*',y1,'+',c,'=',a*x1 + b*y1 + c)
            #print(a,'*',x2,'+',b,'*',y2,'+',c,'=',a*x2 + b*y2 + c)
            if (a*x1 + b*y1 + c) * (a*x2 + b*y2 + c) < 0:
                good = True
        if not good:
            print('no')
            sys.exit()

def solvex(a,b,c,y):
    return (b*y+c)/(-a), y

def solvey(a,b,c,x):
    return x, (a*x+c)/(-b)
    
def intersect(cut1,cut2):
    (a1,b1,c1) = cut1
    (a2,b2,c2) = cut2
    if a1 == 0 and a2 == 0:
        return False
    elif a1 == 0:
        return solvex(a2,b2,c2,-c1/b1)
    elif a2 == 0:
        return solvex(a1,b1,c1,-c2/b2)
    elif b1 == 0 and b2 == 0:
        return False
    elif b1 == 0:
        return solvey(a2,b2,c2,-c1/a1)
    elif b2 == 0:
        return solvey(a1,b1,c1,-c2/a2)
    elif c1 == 0 and c2 == 0:
        return 0,0
    if a1*b2==a2*b1:
        return False

    iy = (a2*c1-a1*c2)/(a1*b2-a2*b1)
    return solvex(a1,b1,c1,iy)

vertices = []
for i, cut1 in enumerate(cuts):
    for cut2 in cuts[:i]:
        p = intersect(cut1,cut2)
        if p and p[0]**2+p[1]**2 < r**2 and not p in vertices:
            vertices.append(p)
F = m + len(vertices) + 1
if F == n:
    print('yes')
else:
    print('no')
