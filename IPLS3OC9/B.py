Ns = [ int(a) for a in input().split() ]
while Ns[-1] != 0:
    Ns += [ int(a) for a in input().split() ]
print("PERFECTION OUTPUT")
for N in Ns[:-1]:
    x = 0
    for i in range(1,N):
        if N % i == 0:
            x += i

    result = ""
    if x == N:
        result = "PERFECT"
    elif x > N:
        result = "ABUNDANT"
    else:
        result = "DEFICIENT"
    print("{0:>5}  {1}".format(N,result))

print("END OF OUTPUT")
