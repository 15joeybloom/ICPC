input()
path1 = input()
path2 = input()

def flip(x):
    if x == 'N':
        return 'S'
    if x == 'S':
        return 'N'
    if x == 'E':
        return 'W'
    if x == 'W':
        return 'E'

path1 = ''.join([flip(x) for x in reversed(path1)])
pattern = path1 + path2

kmp = [0] * len(pattern)
for i in range(1,len(pattern)):
    kmp[i] = kmp[i-1]+1
    while kmp[i] > 0 and pattern[i] != pattern[kmp[i]-1]:
        kmp[i] = kmp[kmp[i]-1]

print(pattern)
print(kmp)
if kmp[-1] > 0:
    print('NO')
else:
    print('YES')
