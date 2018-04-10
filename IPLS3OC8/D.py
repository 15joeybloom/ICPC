import sys

n,k = [ int(a) for a in input().split() ]
As = [ int(a) for a in input().split() ]

groupstart = [0] * n
for i in range(1,n):
    if As[i-1] == As[i]:
        groupstart[i] = groupstart[i-1]
    else:
        groupstart[i] = i
groupend = [n] * n
for i in range(n-2,-1,-1):
    if As[i] == As[i+1]:
        groupend[i] = groupend[i+1]
    else:
        groupend[i] = i+1


def nochange():
    print(max([0]+[groupend[i]-groupstart[i] for i in range(n) if As[i] == 1]))
    print(' '.join([str(a) for a in As]))
    sys.exit()

def allones():
    print(n)
    print(' '.join(['1' for a in As]))
    sys.exit()

if k == 0:
    nochange()

low = 0
try:
    low = As.index(0)
except ValueError:
    allones()

high = low
j = 0
while j < k:
    if As[high] == 0:
        j += 1
    high += 1
    if high == n:
        allones()

best = 0
bestlow = low
besthigh = high
while high <= n:
    fa = low if low == 0 or As[low-1] == 0 else groupstart[low-1]
    fb = high if high == n or As[high] == 0 else groupend[high]
    f = fb-fa

    if best < f:
        best = f
        bestlow = low
        besthigh = high

    if high == n:
        break
    low += 1
    if As[low] == 1:
        low = groupend[low]
    if As[high] == 1:
        high = groupend[high]
    high += 1

print(best)
for i in range(bestlow,besthigh):
    As[i] = 1
print(' '.join([ str(a) for a in As ]))
