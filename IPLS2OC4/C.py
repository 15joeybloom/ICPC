n = int(input())
Ss = []
for i in range(n):
    Ss.append(input())

minfreq = dict()
for i in range(ord('a'), ord('z')+1):
    minfreq[chr(i)] = 500000

for S in Ss:
    freq = dict()
    for i in range(ord('a'), ord('z')+1):
        freq[chr(i)] = 0

    for c in S:
        freq[c] += 1

    for c in freq:
        minfreq[c] = min(minfreq[c], freq[c])

out = ""
l = list(minfreq.items())
l.sort()
for c,x in l:
    out += c*x
print(out)
