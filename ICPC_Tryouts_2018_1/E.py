import queue

n = int(input())
files = input().split()
adj = {file_: [] for file_ in files}
for _ in range(n):
    file_, k = input().split()
    k = int(k)

    for _ in range(k):
        x = input()[7:].split(', ')
        adj[file_] += x

best = None
for start in files:
    parent = {file_ : None for file_ in files}
    q = queue.Queue()
    q.put(start)
    while not q.empty():
        file_ = q.get()
        for child in adj[file_]:
            if parent[child] is None:
                parent[child] = file_
                q.put(child)
    
    if parent[start] is not None:
        cycle = [parent[start]]
        while cycle[-1] != start:
            cycle.append(parent[cycle[-1]])
        if best is None or len(cycle) < len(best):
            best = cycle

if best is None:
    print('SHIP IT')
else:
    print(' '.join(reversed(best)))
