T = int(input())
for i in range(T):
    N = int(input())
    twos = 0
    poweroftwo = 1 
    while 2**poweroftwo <= N:
        twos += (N // 2**poweroftwo)
        poweroftwo += 1
    fives = 0
    poweroffive = 1
    while 5**poweroffive <= N:
        fives += (N // 5**poweroffive)
        poweroffive += 1

    print(min(twos, fives))
