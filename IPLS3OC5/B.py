n,m,k = [ int(a) for a in input().split() ]

army = []
for i in range(m):
    army.append(int(input()))

def hammingdistance(one, two):
    if one == two:
        return 0

    if (one & 1) == (two & 1):
        return hammingdistance(one >> 1, two >> 1)
    else:
        return 1 + hammingdistance(one >> 1, two >> 1)

fedor = int(input())

friends = 0
for i in range(m):
    if hammingdistance(fedor, army[i]) <= k:
        friends += 1

print(friends)
