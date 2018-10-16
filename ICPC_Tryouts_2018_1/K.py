N = int(input())
W = []
L = []
for _ in range(N):
    w, l = [ int(a) for a in input().split() ]
    W.append(w)
    L.append(l)
M = int(input())
T = [ int(a) for a in input().split() ]

graph = []
for i in range(N):

