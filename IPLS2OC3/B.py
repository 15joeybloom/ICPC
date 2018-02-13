n = int(input())
A = [int(x) for x in input().split()]

def canSolve():
  quarters = halves = 0
  for a in A:
    if a == 25:
      quarters += 1
    elif a == 50:
      if quarters >= 1:
        quarters -= 1
        halves += 1
      else:
        return False
    else:
      if halves >= 1 and quarters >= 1:
        halves -= 1
        quarters -= 1
      elif quarters >= 3:
        quarters -= 3
      else:
        return False
  return True

if canSolve():
  print('YES')
else:
  print('NO')

