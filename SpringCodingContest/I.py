q = int(input())
a = int(input())

answers = [1]*(10**6)

for i in range(2,len(answers)):
    for j in range(2*i,len(answers),i):
        answers[j] += i

solution = 0
for i in range(q):
    solution += answers[a]
    a = ((a*a) % 999983) + 1

print(solution)
