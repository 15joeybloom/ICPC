from math import ceil

t = int(input())
for _ in range(t):
    L, v, l, r = [ int(a) for a in input().split() ]
    lanterns = L // v
    firstcovered = ceil(l / v) * v
    if firstcovered == r:
        lanterns -= 1
    elif firstcovered < r:
        lanterns -= 1
        lanterns -= (r - firstcovered) // v

    print(lanterns)
