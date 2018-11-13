import sys

n = int(input())
m = int(input())
a = [ int(x) for x in input().split() ]
b = [ int(x) for x in input().split() ]
if 1 in a or 1 in b:
    print(-1)
    sys.exit(0)

f = m / (b[0] - 1)
for i in range(n-1, 0, -1):
    f += (m + f) / (a[i] - 1)
    f += (m + f) / (b[i] - 1)
f += (m + f) / (a[0] - 1)
print(f)
