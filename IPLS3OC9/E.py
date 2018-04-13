n = int(input())
p = [0]+[int(a) for a in input().split()]
loc = [0]*(n+1)
for i in range(n):
    loc[p[i+1]] = i+1

best = 0
run = 1
for i in range(2,n+1):
    if loc[i] > loc[i-1]:
        run += 1
    else:
        best = max(run,best)
        run = 1
best = max(run,best)

print(n-best)

