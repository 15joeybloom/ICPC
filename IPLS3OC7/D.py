n = int(input())

out = []
while n >= 4:
    out += [n, n-3]
    n -= 4

diff = 0
if n == 3:
    out += [3]
elif n == 2:
    out += [1]
    diff = 1
elif n == 1:
    diff = 1

print(diff)
print(' '.join(map(str,[len(out)]+out)))
