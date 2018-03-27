line = input()

pal = line
for i in range(len(line)-2,-1,-1):
    pal += line[i]

print(pal)
