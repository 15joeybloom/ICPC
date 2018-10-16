def right(d):
    if d == 'N':
        return 'E'
    elif d == 'E':
        return 'S'
    elif d == 'S':
        return 'W'
    else:
        return 'N'
def left(d):
    if d == 'N':
        return 'W'
    elif d == 'W':
        return 'S'
    elif d == 'S':
        return 'E'
    else:
        return 'N'
    
w, h = [ int(a) for a in input().split() ]

def inbounds(x, y):
    return 0 <= x and x <= w and 0 <= y and y <= h

lost = [ [ False for _ in range(h+1) ] for _ in range(w+1) ]
try:
    while True:
        x, y, d = input().split()
        x = int(x)
        y = int(y)

        finished = True
        insts = input()
        for inst in insts:
            if inst == 'L':
                d = left(d)
            elif inst == 'R':
                d = right(d)
            else:
                if d == 'N':
                    future = (x, y + 1)
                elif d == 'W':
                    future = (x - 1, y)
                elif d == 'S':
                    future = (x, y - 1)
                else:
                    future = (x + 1, y)
                if inbounds(future[0], future[1]):
                    x, y = future
                elif not lost[x][y]:
                    finished = False
                    break

        if finished:
            print(x, y, d)
        else:
            lost[x][y] = True
            print(x, y, d, 'LOST')
except EOFError:
    pass
