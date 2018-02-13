import sys

n = int(input())
lower = -2*10**9
upper = 2*10**9

for i in range(n):
    sign, x, ans = input().split()
    x = int(x)
    if ans == 'Y' and sign == '>=' or ans == 'N' and sign == '<':
        lower = max(lower, x)
    elif ans == 'Y' and sign == '>' or ans == 'N' and sign == '<=':
        lower = max(lower, x+1)
    elif ans == 'Y' and sign == '<=' or ans == 'N' and sign == '>':
        upper = min(upper, x)
    else:
        upper = min(upper, x-1)

    if lower > upper:
        print('Impossible')
        sys.exit()
#print(lower,upper)
print(lower)
