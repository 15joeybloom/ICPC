T = int(input())
for t in range(T):
    n,m = [int(a) for a in input().split()]
    adj = [set() for _ in range(n)]
    for _ in range(m):
        a,b = [int(a) for a in input().split()]
        adj[a-1].add(b-1)
        adj[b-1].add(a-1)

    throwngroups = 0
    done = False
    while not done:
        throwing = set()
        for i in range(n):
            if len(adj[i]) == 1:
                throwing.add(i)
        if not throwing:
            done = True
        else:
            throwngroups += 1 
            for throw in throwing:
                adj[throw] = set()
            for i in range(n):
                adj[i] -= throwing
    print(throwngroups)
