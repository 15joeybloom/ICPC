a,b = [ int(a) for a in input().split() ]

if (a * b) % 2 == 0:
    print("Even")
else:
    print("Odd")
