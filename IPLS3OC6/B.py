a,b = input().split()

r = int(int(a+b)**(0.5))

if r**2 == int(a+b):
    print('Yes')
else:
    print('No')

