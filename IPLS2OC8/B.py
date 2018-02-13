S = input()
runs = 0
b = S[0] == 'B'
for s in S:
    if (s == 'B') != b:
        b = (s == 'B')
        runs += 1
print(runs)
