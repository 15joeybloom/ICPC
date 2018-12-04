s, x = [ int(a) for a in input().split() ]

def bits(n):
    b = []
    while n > 0:
        b.append(n&1)
        n >>= 1
    return b

sbits = bits(s)
xbits = bits(x)
nbits = max(len(sbits), len(xbits))
sbits += [0] * (nbits - len(sbits))
xbits += [0] * (nbits - len(xbits))
fixed = [False for _ in sbits]

carry = 0
for i in range(nbits):
    if carry == 0:
        if xbits[i] == 0:
            if sbits[i] == 0:
                fixed[i] = True
            else:



