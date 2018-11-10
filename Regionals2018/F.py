from math import hypot

x, y, x1, y1, x2, y2 = [ int(a) for a in input().split() ]

if x <= x1:
    if y <= y1:
        d = hypot(x-x1,y-y1)
    elif y >= y2:
        d = hypot(x-x1,y-y2)
    else:
        d = x1-x
elif x >= x2:
    if y <= y1:
        d = hypot(x-x2,y-y1)
    elif y >= y2:
        d = hypot(x-x2,y-y2)
    else:
        d = x-x2
elif y <= y1:
    d = y1-y
else:
    d = y-y2

print(d)

