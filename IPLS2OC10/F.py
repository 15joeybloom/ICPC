n, m = [int(a) for a in input().split()]
x, y = [int(a) for a in input().split()]
x-=1
y-=1
adj = [[] for _ in range(n)]
for i in range(m):
    u,v,w = [int(a) for a in input().split()]
    u-=1
    v-=1
    adj[u].append((v,w))
    adj[v].append((u,w))
for i in range(n):
    adj[i].sort(key=lambda x: x[1], reverse=True)

taxi = []
for i in range(n):
    t,c = [int(a) for a in input().split()]
    taxi.append((t,c))

dp = [2**1000]*n
dp[x] = 0
marked1 = [False]*n
stk1 = [x]
while stk1:
    u1 = stk1.pop()
    if marked1[u1]:
        continue
    marked1[u1] = True

    # see where you can get in t_u1
    marked2 = [False]*n
    t_u1, c_u1 = taxi[u1]
    stk2 = [(u1,0)]
    while stk2:
        u2,d = stk2.pop()
        if marked2[u2]:
            continue
        marked2[u2] = True

        dp[u2] = min(dp[u2], dp[u1]+c_u1)
        for v2,w in adj[u2]:
            if not marked2[v2] and w+d <= t_u1:
                stk2.append((v2,w+d))

    for v1,w in adj[u1]:
        if not marked1[v1]:
            stk1.append(v1)
if dp[y] == 2**1000:
    print(-1)
else:
    print(dp[y])
