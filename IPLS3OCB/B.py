N = int(input())
A0 = [ int(a) for a in input().split() ]
A1 = [ int(a) for a in input().split() ]

print(max([ sum(A0[:i+1])+sum(A1[i:]) for i in range(N+1) ]))

