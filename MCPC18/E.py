import sys
n = int(input())

adj = [[] for _ in range(n)]
for _ in range(n-1):
    a, b, c = [ int(a) for a in input().split() ]
    a -= 1
    b -= 1
    adj[a].append((b, c))
    adj[b].append((a, c))

freq = [{} for _ in range(n)]
for i in range(n):
    for child, color in adj[i]:
        if color not in freq[i]:
            freq[i][color] = 0
        freq[i][color] += 1

pruned = [ False for _ in range(n) ]
for i in range(n):
    if pruned[i]:
        continue
    for color, count in freq[i].items():
        if count == 1:
            continue
        stk = [ (i, color, child) for child, childcolor in adj[i] 
                           if childcolor == color and not pruned[child]]
        while stk:
            parent, parentcolor, node = stk.pop()
            pruned[node] = True
            for child, cccc in adj[node]:
                if child == parent:
                    continue
                if parentcolor == cccc:
                    print(0)
                    sys.exit()
                if not pruned[child]:
                    stk.append((node, cccc, child))

print(len(pruned) - sum(pruned))
for i in range(n):
    if not pruned[i]:
        print(i+1)

