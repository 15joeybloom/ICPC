n, x = [int(a) for a in input().split()]
found = [int(a) for a in input().split()]
foundsum = sum(found)
print((abs(foundsum)-1) // x + 1)
