n = int(input())

subs = []
first = []
last = []

for i in range(n):
    s = input()
    subs.append([set() for _ in range(101)])
    first.append(s)
    last.append(s)
    for j in range(len(s)):
        for k in range(j+1,len(s)):
            subs[k-j].add(s[j:k])

for i in range(m):
    a,b = [ int(o) for o in input().split() ]
    subs.append([set() for _ in range(101)])
    first.append(first[a])
    if len(first[-1]) < 101:
        first[-1] += first[b]
        first[-1] = first[-1][:101]
    last.append(last[b])
    if len(last[-1]) < 101:
        last[-1] = last[b] + last[-1]
        last[-1] = last[-1][-101:]


