s1 = input()
s2 = input()

dest = s1.count('+')-s1.count('-')
center = s2.count('+')-s2.count('-')

distr = [0.0]*10+[1.0]+[0.0]*10

for i in range(s2.count('?')):
    nextdistr = [0.0]*21
    for j in range(1,20):
        nextdistr[j-1] += 0.5*distr[j]
        nextdistr[j+1] += 0.5*distr[j]
    distr = nextdistr

print(distr[10+dest-center])
