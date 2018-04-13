import sys

n = int(input())
a = [ int(a) for a in input().split() ]

s = sum(a)
if s % 3 != 0:
    print(0)
    sys.exit()

counter = a[0]
first = 0
firsts = [0]
lasts = []
for i in range(1,n):
    if counter == s//3:
        first += 1
    firsts.append(first)
    if counter == 2*s//3:
        lasts.append(i)
    counter += a[i]

answer = 0
for i in lasts:
    if i >= 2:
        answer += firsts[i-1]

print(answer)
#print(firsts)
#print(lasts)

