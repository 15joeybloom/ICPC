n = int(input())
xs = [int(a) for a in input()]
ys = [int(a) for a in input()]

counter = 0
for x,y in zip(xs,ys):
    counter += min(abs(x-y), min(x,y)+10-max(x,y))

print(counter)
