N = int(input())
while N > 0:
    boxes = []
    for i in range(N):
        weight, load = [ int(a) for a in input().split() ]
        boxes.append((weight, load))

    lightest = [3000**2] * (N+1)

    for i in range(N):
        w, l = boxes[N-1-i]
        for j in range(i-1, -1, -1):
            if lightest[j+1] <= l:
                lightest[j+2] = min(lightest[j+2], lightest[j+1] + w)
        if w < lightest[1]:
            lightest[1] = w

    best = 0
    for i in range(1, N+1):
        if lightest[i] != 3000**2:
            best = i
    print(best)

    N = int(input())
