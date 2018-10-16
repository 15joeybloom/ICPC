n, m = [ int(a) for a in input().split() ]
segments = []
for _ in range(n):
    l, r = [ int(a) for a in input().split() ]
    segments.append((l, r))

bad = []
for i in range(1, m+1):
    inASegment = False
    for l, r in segments:
        if l <= i and i <= r:
            inASegment = True
            break
    if not inASegment:
        bad.append(i)

print(len(bad))
if bad:
    print(' '.join([str(a) for a in bad]))
