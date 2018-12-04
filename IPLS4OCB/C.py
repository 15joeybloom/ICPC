import sys
from math import hypot

a, b, c = [ int(a) for a in input().split() ]
x1, y1, x2, y2 = [ int(a) for a in input().split() ]

# translate to origin
c += a*x1+b*y1
x2 -= x1
y2 -= y1

# flip so x2,y2 first quadrant
if x2 < 0:
    x2 = -x2
    a = -a
if y2 < 0:
    y2 = -y2
    b = -b

if a == 0 or b == 0 or x2 == 0 or y2 == 0 or a*b > 0:
    print(x2+y2)
    sys.exit()
xint = -c/a
yint = -c/b
if 0 <= xint and xint <= x2:
    p1 = (xint, 0)
elif 0 <= yint and yint <= y2:
    p1 = (0, yint)
else:
    print(x2+y2)
    sys.exit()

y2int = (-c-b*y2)/a
x2int = (-c-a*x2)/b
if y2int <= x2:
    p2 = (y2int, y2)
else:
    p2 = (x2, x2int)

print(hypot(p1[0], p1[1]) + hypot(p2[0]-p1[0], p2[1]-p1[1]) + hypot(x2-p2[0], y2-p2[1]))

# walk to x intercept or y intercept

