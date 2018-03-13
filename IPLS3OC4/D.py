while True:
    try:
        M,N = [int(a) for a in input().split()]
        board = []
        for m in range(M):
            board.append(input())
        X,Y = [int(a) for a in input().split()]

        cont = board[X][Y]

        component = [[0]*N for _ in range(M)]

        counter = 1
        for m in range(M):
            for n in range(N):
                if board[m][n] == cont and component[m][n] == 0:
                    
                    stk = [(m,n)]
                    while stk:
                        i,j = stk.pop() 
                        if board[i][j] == cont and component[i][j] == 0:
                            component[i][j] = counter
                            if i > 0:
                                stk.append((i-1,j))
                            if i < M-1:
                                stk.append((i+1,j))
                            stk.append( (i, (j+1)%N) )
                            stk.append( (i, (j-1)%N) )

                    counter += 1

        freq = [0] * counter
        for m in range(M):
            for n in range(N):
                freq[component[m][n]] += 1

        p = 0
        for i in range(counter):
            if i != 0 and i != component[X][Y]:
                p = max(p, freq[i])

        print(p)

        input()
    except EOFError:
        break
