n, m = [int(a) for a in input().split()]
v = [int(a) for a in input().split()]
adj = [set() for _ in range(n)]
for i in range(m):
    x,y = [int(a) for a in input().split()]
    x-=1
    y-=1
    adj[x].add(y)
    adj[y].add(x)

totalenergy = 0
for i in range(n):
    '''
    minenergy = sum(v)
    print('minenergy', minenergy)
    minx = -1 

    for x in range(n):
        if len(adj[x]) == 0:
            continue
        energy = sum([v[y] for y in adj[x]])
        print('energy', x, energy)
        if energy < minenergy:
            minenergy, minx = energy, x
    
    totalenergy += minenergy
    for y in adj[minx]:
        adj[y].remove(minx)
    adj[minx].clear()
    '''

    attached = list([(x,vv) for x,vv in enumerate(v) if adj[x]])
    if not attached:
        break
    maxx,maxv = max(attached, key=lambda x:x[1])
    totalenergy += sum([v[y] for y in adj[maxx]])
    for y in adj[maxx]:
        adj[y].remove(maxx)
    adj[maxx].clear()

print(totalenergy)
