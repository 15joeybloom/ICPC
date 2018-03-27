def sumdigits(x):
    if x < 10:
        return x
    return sumdigits(x//10)+(x%10)

a,b,c = [ int(a) for a in input().split() ]

solutions = []
for i in range(82):
    x = b * i**a + c
    if 0 < x and x < 10**9 and sumdigits(x) == i:
        solutions.append(x)

print(len(solutions))
if solutions:
    print(' '.join(map(str,solutions)))
