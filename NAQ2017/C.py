import sys
n = int(input())
coins = [int(a) for a in input().split()]

#print(coins)
def greedy(x):
    y = 0
    for c in reversed(coins):
        y += x // c
        x %= c
    return y

N = coins[-1]+coins[-2]
infinity = 10**10
dp = [infinity] * N
greedy = [infinity] * N

dp[0] = 0
for c in coins:
    for i in range(c,N):
        dp[i] = min(dp[i],dp[i-c]+1)

for i in range(N):
    if greedy(i) != dp[i]:
        #print('counter example:', i)
        #print('greedy:', greedy(i))
        #print('dp:', dp[i])
        print('non-canonical')
        sys.exit()
print('canonical')
