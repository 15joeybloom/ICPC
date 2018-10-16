import math
eps = 10**-6
T = int(input())
for t in range(T):
    N, F = [ int(a) for a in input().split() ]
    r = [ math.pi*int(a)**2 for a in input().split() ]

    low = 0
    high = math.pi*10000**2
    while low + eps < high:
        V = (low + high) / 2.0

        pies = 0
        for x in r:
            pies += x // V

        # print(low, V, high, pies)
        if pies >= F + 1:
            low = V
        else:
            high = V
    print(low)
