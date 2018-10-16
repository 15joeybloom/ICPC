T = int(input())
for t in range(T):
    N = int(input())
    calls = [ int(a) for a in input().split() ]
    mile = sum([ 10 + 10 * (call // 30) for call in calls])
    juice = sum([ 15 + 15 * (call // 60) for call in calls])
    if mile == juice:
        winner = 'Mile Juice'
        cost = mile
    elif mile < juice:
        winner = 'Mile'
        cost = mile
    else:
        winner = 'Juice'
        cost = juice
    print('Case {0}: {1} {2}'.format(t+1, winner, cost))

