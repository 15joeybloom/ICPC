n = int(input())
fs = [ int(a) - 1 for a in input().split()]

love = False
for i in range(n):
    if fs[fs[fs[i]]] == i:
        love = True

if love:
    print('YES')
else:
    print('NO')

