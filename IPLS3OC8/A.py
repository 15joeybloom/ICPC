import sys

ns = [ int(a) for a in input().split() ]

ns.sort()

for i in range(3):
    if ns[0] == ns[1] and ns[1] == ns[2] and ns[2] == ns[3]:
        if ns[4] == ns[5]:
            print('Elephant')
        else:
            print('Bear')
        sys.exit()
    ns = ns[1:] + [ns[0]]
print('Alien')
