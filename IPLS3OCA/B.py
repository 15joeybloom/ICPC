import sys

n,m = [ int(a) for a in input().split() ]

twos = n//2
ones = n%2

while (twos+ones)%m != 0 and twos > 0:
    twos -= 1
    ones += 2

if (twos+ones)%m != 0:
    print(-1)
else:
    print(twos+ones)
