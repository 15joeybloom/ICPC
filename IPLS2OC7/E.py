n,p = [int(a) for a in input().split()]
named = []
for i in range(n):
    x,y = [int(a) for a in input().split()]
    named.append((x,y))

agree = [0] * (n+1)
for x,y in named:
    agree[x] += 1
    agree[y] += 1

freq = [0] * (n+1)
for a in agree[1:]:
    freq[a] += 1

partial = [0] * (n+1)
partial[n] = freq[n]
for i in range(n-1,-1,-1):
    partial[i] = partial[i+1] + freq[i]

counter = 0
for i in range(n+1):
    if i < p-i:
        counter += freq[i] * partial[p-i]

print('Named:', named)
print('Agree:', agree)
print('Freq:', freq)
print('Partial:', partial)
print(counter)
