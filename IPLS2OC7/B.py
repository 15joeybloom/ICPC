n = int(input())
rats = []
wc = []
men = []
captain = []
for i in range(n):
    name, role = input().split()
    if role == 'rat':
        rats.append(name)
    elif role == 'child' or role == 'woman':
        wc.append(name)
    elif role == 'man':
        men.append(name)
    elif role == 'captain':
        captain.append(name)

for rat in rats:
    print(rat)
for person in wc:
    print(person)
for man in men:
    print(man)
for cap in captain:
    print(cap)

