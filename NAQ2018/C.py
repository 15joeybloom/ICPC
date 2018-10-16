def readtable(entries, table):
    for _ in range(entries):
        ints = [ int(a) for a in input().split() ]
        table[(ints[0]-1, ints[1]-1)] = [0] + ints[2:]
ww, wb, bw, bb, L = [ int(a) for a in input().split() ]
tableww = {}
tablewb = {}
tablebw = {}
tablebb = {}
readtable(ww, tableww)
readtable(wb, tablewb)
readtable(bw, tablebw)
readtable(bb, tablebb)

notes = [ int(a) for a in input().split() ]

def black(note):
    return note % 12 in [0, 2, 5, 7, 10]

dp = [[10**10 for _ in range(5)] for _ in range(L)]
for i in range(5):
    dp[0][i] = 0

for i in range(1, L):
    interval = notes[i]-notes[i-1]
    if interval == 0:
        for j in range(5):
            dp[i][j] = dp[i-1][j]
    elif interval > 0:
        for j in range(5):
            for k in range(5):
                if black(notes[i]):
                    if black(notes[i-1]):
                        table = tablebb
                    else:
                        table = tablewb
                else:
                    if black(notes[i-1]):
                        table = tablebw
                    else:
                        table = tableww
                if (k, j) in table:
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+table[(k, j)][interval])
    else:
        for j in range(5):
            for k in range(5):
                if black(notes[i]):
                    if black(notes[i-1]):
                        table = tablebb
                    else:
                        table = tablebw
                else:
                    if black(notes[i-1]):
                        table = tablewb
                    else:
                        table = tableww
                if (j, k) in table:
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+table[(j, k)][-interval])

print(min(dp[-1]))
