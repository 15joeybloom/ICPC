# Author: John Qian

from collections import defaultdict


n, m = map(int, input().strip().split())

flights = []
for i in range(m):
    flights.append([int(a) for a in input().split()] + [i])

outfrom = defaultdict(list)
for flight in flights:
    outfrom[flight[0]].append(flight)

def frust(fi, F={}):
    if fi not in F:
        f = flights[fi]
        if f[1] == n:
            F[fi] = 0
        else:
            F[fi] = min((f2[2] - f[3])**2 + frust(f2[4]) for f2 in outfrom[f[1]] if f2[2] > f[3])
    return F[fi]

print(min(f[2]**2 + frust(f[4]) for f in outfrom[1]))
