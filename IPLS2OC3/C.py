n, m = [int(x) for x in input().split()]

if n > m+1:
  print(-1)
elif 2*(n+1) < m:
  print(-1)
else:
  out = ""
  while n > 0 or m > 0:
    if n == 0:
      out += '1' * m
      m = 0
    elif n > m:
      out += '0'
      n -= 1
    elif n == m:
      out += '10' * n
      n = m = 0
    else:
      out += '110'
      n -= 1
      m -= 2
  print(out)
