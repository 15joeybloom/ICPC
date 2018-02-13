def solve(tokens):
    g = int(tokens[0])
    A = [int(x) for x in tokens[1:]]

    for i in range(1,g):
        if A[i-1]+1 != A[i]:
            print(i+1)
            return

n = int(input())
for _ in range(n):
    tokens = input().split()
    solve(tokens)

