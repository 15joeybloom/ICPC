print('INTERSECTING LINES OUTPUT')
N = int(input())
for _ in range(N):
    x1, y1, x2, y2, x3, y3, x4, y4 = [ int(a) for a in input().split() ]
    if x1 == x2 and x3 == x4:
        if x1 == x3:
            print('LINE')
        else:
            print('NONE')
    elif x1 == x2:
        print('POINT {0:0.2f} {1:0.2f}'.format(x1, y3+(y4-y3)*(x1-x3)/(x4-x3)))
    elif x3 == x4:
        print('POINT {0:0.2f} {1:0.2f}'.format(x3, y1+(y2-y1)*(x3-x1)/(x2-x1)))
    else:
        m1 = (y2-y1)/(x2-x1)
        m3 = (y4-y3)/(x4-x3)
        if m1 == m3:
            if (y4-y1)*(x2-x1) == (y2-y1)*(x4-x1):
                print('LINE')
            else:
                print('NONE')
        else:
            x = (y3-y1+m1*x1-m3*x3)/(m1-m3)
            y = m3*(x-x3)+y3
            print('POINT {0:0.2f} {1:0.2f}'.format(x, y))

print('END OF OUTPUT')
