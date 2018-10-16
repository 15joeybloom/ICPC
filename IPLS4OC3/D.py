T = int(input())
for t in range(T):
    sticks = [ int(a) for a in input().split() ]
    M, sticks = sticks[0], sticks[1:]

    total = sum(sticks)
    if total % 4 != 0:
        print('no')
        continue

    side = total // 4

    bad = False
    sofar = 0
    for i in sticks:
        sofar += i
        if sofar > side:
            bad = True
            break
        if sofar == side:
            sofar = 0
    if bad:
        print('no')
    else:
        print('yes')

