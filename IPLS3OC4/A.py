T = int(input())
for t in range(T):
    ns = [int(a) for a in input().split()]
    N = ns[0]
    ages = ns[1:]

    print('Case ' + str(t+1) + ':', ages[N//2])


