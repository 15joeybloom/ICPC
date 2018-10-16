'''
valid = {}
stk = [[ '...', '...', '...' ]]
while stk:
    grid = stk.pop()
    if not grid in valid:
        valid[grid] = True
    
    if not winning(grid):
    '''


N = int(input())
for T in range(N):
    grid = [input() for i in range(3)]
    if T < N-1:
        input()

    '''
    if valid[grid]:
        print('YES')
    else:
        print('NO')
        '''
    exs = 0
    os = 0
    for i in range(3):
        for j in range(3):
            if grid[i][j] == 'X':
                exs += 1
            elif grid[i][j] == 'O':
                os += 1
    
    xthrees = 0
    othrees = 0
    for i in range(3):
        if grid[i][0] == grid[i][1] and grid[i][1] == grid[i][2]:
            if grid[i][0] == 'X':
                xthrees += 1
            elif grid[i][0] == 'O':
                othrees += 1
        if grid[0][i] == grid[1][i] and grid[1][i] == grid[2][i] and grid[0][i] in 'XO':
            if grid[0][i] == 'X':
                xthrees += 1
            elif grid[0][i] == 'O':
                othrees += 1
    if grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2]:
        if grid[0][0] == 'X':
            xthrees += 1
        elif grid[0][0] == 'O':
            othrees += 1
    if grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0]:
        if grid[0][2] == 'X':
            xthrees += 1
        elif grid[0][2] == 'O':
            othrees += 1
    threes = xthrees + othrees

    if exs == 5 and os == 4 and xthrees == 2:
        print('yes')
    elif threes > 1 or exs - os not in range(2):
        print('no')
    elif othrees > 0 and exs != os:
        print('no')
    elif xthrees > 0 and exs == os:
        print('no')
    else:
        print('yes')
