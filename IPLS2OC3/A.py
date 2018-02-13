N = int(input())
A = [int(x) for x in input().split()]

x = min(A)
y = [a for a in A if a != x]

if y:
  print(min(y))
else:
  print('NO')
