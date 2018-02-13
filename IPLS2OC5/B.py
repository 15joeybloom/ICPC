n,m = [int(a) for a in input().split()]
f = [int(a) for a in input().split()]

f.sort()

diff = 100000000000000000000
for i in range(n-1,m):
    diff = min(diff, f[i]-f[i+1-n])

print(diff)

