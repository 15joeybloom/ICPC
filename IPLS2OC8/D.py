#!/usr/bin/python3

N = int(input())
for t in range(N):
    K = int(input())
    durations = [int(a) for a in input().split()]
    trains = [int(a) for a in input().split()]
    candidates = list(zip(durations, trains))
    candidates = [(a,x-30) for a,x in candidates if x >= 0]
    candidates.sort(key=lambda x: x[1])

    dp = [dict() for c in candidates]
    def solve(c, t):
        if c >= len(candidates):
            return 0
        if t in dp[c]:
            return dp[c][t]
        dur, tra = candidates[c]
        result = solve(c+1, t)
        if t + dur <= tra:
            result = max(result, 1 + solve(c+1, t+dur))
        dp[c][t] = result
        return result
        
    print('Case ' + str(t+1) + ':', len(candidates)-solve(0, 0))
