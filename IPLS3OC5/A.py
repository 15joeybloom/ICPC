n, x = [ int(a) for a in input().split() ]

distressed = 0
for i in range(n):
    tokens = input().split()
    y = int(tokens[1])
    if tokens[0] == '+':
        x += y
    elif x < y:
        distressed += 1
    else:
        x -= y

print(x, distressed)
