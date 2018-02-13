names = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

n = int(input())
xx = input()

for name in names:
    if n != len(name):
        continue
    good = True
    for i in range(len(name)):
        if not xx[i] in ['.', name[i]]:
            good = False
    if good:
        print(name)
