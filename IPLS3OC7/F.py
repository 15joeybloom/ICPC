n,m,c = [ int(a) for a in input().split() ]

papers = [0]*n

papers[n//2] = int(input())
print(n//2+1)

high = n//2+1
low = n//2
while papers[0] == 0 or papers[-1] == 0:
    nex = int(input())

    if nex < papers[low]:
        if low == 0:
            papers[0] = nex
            print(1)
        else:
            print(low)
            low -= 1
            papers[low] = nex
    elif nex > papers[high-1]:
        if high == n:
            papers[-1] = nex
            print(n)
        else:
            papers[high] = nex
            high += 1
            print(high)
    elif nex == papers[low] and low > 0:
        print(low)
        low -= 1
        papers[low] = nex
    elif nex == papers[high-1] and high < n:
        papers[high] = nex
        high += 1
        print(high)
    elif high == n:
        for i in range(high-1, low-1, -1):
            if nex > papers[i]:
                print(i+1)
                papers[i] = nex
                break
    else:
        for i in range(low, high):
            if nex < papers[i]:
                print(i+1)
                papers[i] = nex
                break



            

