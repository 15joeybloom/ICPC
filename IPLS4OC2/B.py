denoms = [5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000]
maxamt = 30010
dp = [[0 for _ in range(maxamt)] for _ in denoms]
for i in range(0, maxamt, denoms[0]):
    dp[0][i] = 1
for i in range(1, len(denoms)):
    for j in range(0, denoms[i]):
        dp[i][j] = dp[i-1][j]
    for j in range(denoms[i], maxamt):
        dp[i][j] = dp[i-1][j] + dp[i][j-denoms[i]]

def get_line():
    money = input().strip()
    cents = int(money.replace('.',''))
    return money,cents

money,cents = get_line()
while cents != 0:
    answer = dp[-1][cents]
    print("{0:>6}{1:>17d}".format(money, answer))
    money,cents = get_line()

