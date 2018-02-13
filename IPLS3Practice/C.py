n,m = [int(a) for a in input().split()]
fs = [int(a) for a in input().split()]
fs.sort()
solution = sum(fs)
start = 0
while start + n <= len(fs):
    solution = min(solution, fs[start+n-1]-fs[start])
    start += 1
print(solution)
