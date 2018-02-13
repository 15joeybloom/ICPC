from sys import exit

x0, y0 = [int(a) for a in input().split()]
n = int(input())
insts = []
for i in range(n):
    insts.append(input())

def runinsts(insts):
    x = 0
    y = 0
    direction = 0
    for inst in insts:
        if inst == 'Left':
            direction -= 1
        elif inst == 'Right':
            direction += 1
        elif direction % 4 == 0:
            y += 1
        elif direction % 4 == 1:
            x += 1
        elif direction % 4 == 2:
            y -= 1
        else:
            x -= 1

    return x,y

for i in range(n):
    original = insts[i]

    for fix in ['Left', 'Right', 'Forward']:
        insts[i] = fix
        x,y = runinsts(insts)
        if x == x0 and y == y0:
            print(i+1, fix)
            exit()

    insts[i] = original
