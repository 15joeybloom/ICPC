n = int(input())
dirs = input()

runs = []
current = 1
for i in range(1, n-1):
    if dirs[i-1] == dirs[i]:
        current += 1
    else:
        runs.append(current)
        current = 1
runs.append(current)

if dirs[0] == 'L':
    result = list(range(runs[0]+1, 0, -1))
    low = runs[0]+1
    runi = 1
else:
    result = [1]
    low = 1
    runi = 0

while runi < len(runs):
    if runi == len(runs)-1:
        result += range(low+1, n+1)
        runi += 1
    else:
        # result += range(low+1+runs[runi+1], low+1+runs[runi+1]+runs[runi]) 
        # result += range(low+runs[runi+1], low, -1)
        result += range(low+1, low+runs[runi])
        result += range(low+runs[runi+1]+runs[runi], low+runs[runi]-1, -1)
        low += runs[runi] + runs[runi+1]
        runi += 2

print('\n'.join([str(x) for x in result]))
