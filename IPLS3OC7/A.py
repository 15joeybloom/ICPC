x = [False]*1010

x[0] = True
a = 0
b = 1
while b <= 1000:
    x[b] = True
    b = a + b
    a = b - a

name = ''
n = int(input())
for i in range(1,n+1):
    if x[i]:
        name += 'O'
    else:
        name += 'o'

print(name)

