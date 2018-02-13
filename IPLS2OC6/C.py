n = int(input())
ps = [int(a) for a in input().split()]
fronts = [int(a) for a in input().split()]
backs = [int(a) for a in input().split()]

shirts = list(zip(ps,fronts,backs))
shirts.sort()
bought = [False] * n

ptrs = [0] * 4
def mvptrs():
    for i in range(1,len(ptrs)):
        while ptrs[i] < n and ((shirts[ptrs[i]][1] != i and shirts[ptrs[i]][2] != i) or bought[ptrs[i]]):
            ptrs[i] += 1

mvptrs()

m = int(input())
colors = [int(a) for a in input().split()]
def serve(i):
    if ptrs[colors[i]] >= n:
        print(-1, end='')
    else:
        print(shirts[ptrs[colors[i]]][0], end='')
        bought[ptrs[colors[i]]] = True
        mvptrs()
serve(0)
for i in range(1,m):
    print(' ', end='')
    serve(i)
print()
