from sys import exit
from collections import deque

n,m,k = [int(x) for x in input().split()]

maze = []
maze.append('#'*(m+2))
for _ in range(n):
  maze.append(list('#'+input()+'#'))
maze.append('#'*(m+2))

def mark(i,j):
  #print('{} {}'.format(i,j))
  global k
  maze[i][j] = 'X'
  k -= 1
  if k == 0:
    for row in maze[1:n+1]:
      print(''.join(row[1:m+1]))
    exit()

def findDot():
  for i in range(1,n+1):
    for j in range(1,m+1):
      if maze[i][j] == '.':
        return i,j

visited = [[False] * (m+2) for _ in range(n+2)]
def soln():
  def solve(i,j):
    if maze[i][j] == '.':
      visited[i][j] = True
      if maze[i+1][j] == '.' and not visited[i+1][j]:
        stk.append((i+1,j))
        return False
      if maze[i-1][j] == '.' and not visited[i-1][j]:
        stk.append((i-1,j))
        return False
      if maze[i][j+1] == '.' and not visited[i][j+1]:
        stk.append((i,j+1))
        return False
      if maze[i][j-1] == '.' and not visited[i][j-1]:
        stk.append((i,j-1))
        return False
      mark(i,j)
      visited[i][j] = False
      return True
  x,y = findDot()
  stk = [(x,y)]
  while stk:
    (i,j) = stk[-1]
    if solve(i,j):
      stk.pop()

soln()
#for row in maze[1:n+1]:
#  print(''.join(row[1:m+1]))
