import sys
n = int(input())
s = []
for i in range(n):
    s.append(input())
m = len(s[0])

def no():
    print(-1)
    sys.exit()

def rotate(st):
    return st[1:] + st[0]

def getrots(st,i):
    rotated = st
    for j in range(m):
        if rotated == s[i]:
            return j
        rotated = rotate(rotated)
    no()

ans = 10000000000000000000
for i in range(n):
    rots = [getrots(x,i) for x in s]
    ans = min(ans, sum(rots))
print(ans)
