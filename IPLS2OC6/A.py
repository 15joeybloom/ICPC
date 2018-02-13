n,k,t = [int(a) for a in input().split()]

out = [0] * n

totalsat = 0
i = 0
while t / 100 >= (totalsat + 1) / (n * k):
    if out[i] == k:
        i += 1
    out[i] += 1
    totalsat += 1

outstr = ""
outstr += str(out[0])
for x in out[1:]:
    outstr += " " + str(x)

print(outstr)
