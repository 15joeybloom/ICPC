try:
    while True:
        line1 = input()
        line2 = input()
        dp = [[0 for _ in line2] for _ in line1]

        dp[0][0] = 1 if line1[0] == line2[0] else 0
        for i in range(1, len(line2)):
            dp[0][i] = 1 if dp[0][i-1] == 1 or line1[0] == line2[i] else 0
        for i in range(1, len(line1)):
            dp[i][0] = 1 if dp[i-1][0] == 1 or line1[i] == line2[0] else 0
            for j in range(1, len(line2)):
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                if line1[i] == line2[j]:
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1])
        print(dp[-1][-1])
except EOFError:
    pass
