N = int(input())
As = [0] + [int(a) for a in input().split()] + [0]

total = 0
for i in range(N+1):
    total += abs(As[i+1]-As[i])

for i in range(1,N+1):
    if As[i-1] == As[i] or As[i] == As[i+1] or \
            (As[i-1] < As[i]) == (As[i] < As[i+1]):
        print(total)
    else:
        da = abs(As[i-1]-As[i])
        db = abs(As[i]-As[i+1])
        print(total-2*min(da,db))
