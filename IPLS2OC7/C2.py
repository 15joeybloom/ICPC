a1,d1 = [int(a) for a in input().split()]
a2,d2 = [int(a) for a in input().split()]
a3,d3 = [int(a) for a in input().split()]
a4,d4 = [int(a) for a in input().split()]

maxa1 = max(a1,a2)
mina1 = min(a1,a2)
maxa3 = max(a3,a4)
mina3 = min(a3,a4)
maxd1 = max(d1,d2)
mind1 = min(d1,d2)
maxd3 = max(d3,d4)
mind3 = min(d3,d4)

def trysolve(a1,d1,a3,d3):
    if a1 > a3 and d1 > d3:
        print('Team 1')
        return True
    elif a3 > a1 and d3 > d1:
        print('Team 2')
        return True
    return False
def solve(a1,d1,a3,d3):
    if not trysolve(a1,d1,a3,d3):
        print('Draw')

if (maxa3,maxd3) in [(a3,d4),(a4,d3)]:
    if (maxa1,maxd1) in [(a1,d2),(a2,d1)]:
        if maxa1 > axa3 and maxd1 > maxd3:
            print('Team 1')
        elif maxa3 > maxa1 and maxd3 > maxd1:
            print('Team 2')
        else:
            print('Draw')
    elif (maxa1 > maxa3 and mind1 > maxd3) or (mina1 > maxa3 and maxd1 > maxd3):
        print('Team 1')
    elif maxa3 > maxa1 and maxd3 > mind1 and maxa3 > mina1 and maxd3 > mind1:
        print('Team 2')
    else:
        print('Draw')
elif (maxa1,maxd1) in [(a1,d2),(a2,d1)]:
    if (maxa3 > maxa1 and mind3 > maxd1) or (mina3 > maxa1 and maxd3 > maxd1):
        print('Team 2')
    elif maxa1 > maxa3 and maxd1 > mind3 and maxa1 > mina3 and maxd1 > mind3:
        print('Team 1')
    else:
        print('Draw')
elif (maxa1 > maxa3 and maxa1 > mina3 and mind1 > maxd3 and mind1 > mind3
        ) or (mina1 > maxa3 and mina1 > mina3 and maxd1 > maxd3 and maxd1 > mind3):
    print('Team 1')
elif ((maxa3 > maxa1 and mind3 > mind1) or (mina3 > maxa1 and maxd3 > mind1)
        ) and ((maxa3 > mina1 and mind3 > maxd1) or (mina3 > mina1 and maxd3 > maxd1)):
    print('Team 2')
else:
    print('Draw')

