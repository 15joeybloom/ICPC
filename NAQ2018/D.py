L, W = [ int(a) for a in input().split() ]
lanes = [()]
for _ in range(L):
    O, I, S = [ int(a) for a in input().split() ]
    lanes.append((O,I,S))
P, moves = input().split()
P = int(P)

squish = False
location = (L+1, P)
t = 0
for move in moves:
    if move == 'U':
        location = (location[0]-1, location[1])
    elif move == 'D':
        location = (location[0]+1, location[1])
    elif move == 'L':
        location = (location[0], location[1]-1)
    else:
        location = (location[0], location[1]+1)

    if location[0] == 0:
        t += 1
        continue
    if location[0] == L+1:
        t += 1
        continue
    O,I,S = lanes[location[0]]
    if location[0] % 2 == 1:
        x = location[1]
    else:
        x = W-1-location[1]
    newx = (x - O - S * t) % I
    #print('t =', t)
    #print(O,I,S)
    #print(x)
    #print(newx)
    #print(location)
    if S == 0:
        if newx == 0:
            #print('squished')
            squish = True
            break
    elif 0 < newx and newx <= S % I:
        #print('squished')
        squish = True
        break
    t += 1

if squish or location[0] != 0:
    print('squish')
else:
    print('safe')
