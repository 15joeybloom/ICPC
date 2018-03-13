def middleSquare(a):
    a2str = str(a*a)

    while len(a2str) < 8:
        a2str = '0' + a2str

    return int(a2str[2:6])


a0 = int(input())
while a0 != 0:
    visited = set([a0])

    a = middleSquare(a0)
    while not a in visited:
        visited.add(a)
        a = middleSquare(a)

    print(len(visited))

    a0 = int(input())
