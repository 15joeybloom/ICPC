N = int(input())
scores = []
for i in range(N):
    scores.append([int(a) for a in input().split()])

best = 0
diff = 0
for Si, Ti in scores:
    diff = diff + Si - Ti
    if abs(diff) > abs(best):
        best = diff

if best > 0:
    print(1, best)
else:
    print(2, -best)

