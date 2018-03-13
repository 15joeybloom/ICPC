img = []

H,W = [ int(a) for a in input().split() ]
while H != 0 and W != 0:
    W = W*4
    for h in range(H):
        row = int(input(),base=16)
        bits = "{0:#0b}".format(row)
        bits = bits[2:]
        bits = '0'*(W-len(bits)) + bits
        img.append(bits)

    component = [[0]*W for _ in range(H)]
    glyphs = []
    holes = []
    loc = [-1]
    rep = [(-1,-1)]

    counter = 1
    for m in range(H):
        for n in range(W):
            if component[m][n] == 0:
                color = img[m][n]

                if img[m][n] == '1':
                    loc.append(len(glyphs))
                    glyphs.append(counter)
                else:
                    loc.append(len(holes))
                    holes.append(counter)
                rep.append((m,n))
                
                stk = [(m,n)]
                while stk:
                    i,j = stk.pop() 
                    if img[i][j] == color and component[i][j] == 0:
                        component[i][j] = counter
                        if i > 0:
                            stk.append((i-1,j))
                        if i < H-1:
                            stk.append((i+1,j))
                        if j > 0:
                            stk.append((i,j-1))
                        if j < W-1:
                            stk.append((i,j+1))

                counter += 1

    freq = [0] * len(glyphs)
    for hole in holes:
        m,n = rep[hole]
        while img[m][n] == '0' and m >= 0:
            m -= 1

        if m >= 0:
            freq[loc[component[m][n]]] += 1

    freq.sort()

    outstr = ''
    for f in freq:
        if f == 0:
            outstr += 'W'
        elif f == 1:
            outstr += 'A'
        elif f == 2:
            outstr += 'K'
        elif f == 3:
            outstr += 'J'
        elif f == 4:
            outstr += 'S'
        elif f == 5:
            outstr += 'D'

    # for i in img:
        # print(i)
    # print()
    # for i in component:
        # print(''.join(map(str,i)))
    print(outstr)

    img = []
    H,W = [ int(a) for a in input().split() ]
