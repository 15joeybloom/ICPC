T = int(input())
for i in range(T):
    N = int(input())

    freq = [0]*10

    for i in range(1,N+1):
        j = i
        while j >= 10:
            freq[j%10] += 1
            j //= 10
        freq[j%10] += 1

    print(' '.join(map(str,freq)))
