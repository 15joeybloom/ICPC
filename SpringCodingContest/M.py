nrows = int(input())
grid = []
for i in range(nrows):
    grid.append(input().split(","))
numElements = 0
for line in grid:
    if len(line) > numElements:
        numElements = len(line)

def get(y,x):
    if x < len(grid[y]):
        return grid[y][x]
    return ""

longests = [0] * numElements
for x in range(numElements):
    for y in range(nrows):
        if len(get(y,x)) > longests[x]:
            longests[x] = len(grid[y][x])

def printRowSpacer():
    temp = "$"
    for l in longests:
        temp = temp + ("-"*l) + "$"
    print(temp)

def isInt(stri):
    try:
        int(stri)
        return True
    except:
        return False

def pad(inp,leng):
    spacer = ((leng - len(inp))*" ")
    if isInt(inp):
        return spacer + inp
    else:
        return inp + spacer

printRowSpacer()
for y in range(nrows):
    rstring = "|"
    for x in range(numElements):
        rstring += pad(get(y,x),longests[x]) + "|"
    print(rstring)
    printRowSpacer()
