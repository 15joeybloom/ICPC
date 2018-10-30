rain = input()
counter = 0
maxi = -1
mini = -1
maxc = 0
minc = 0
for i in range(len(rain)):
    x = rain[i]
    if x == 'B':
        counter += 1
    elif x == 'R':
        counter -= 1
    if counter > maxc:
        maxc = counter
        maxi = i
    if counter < minc:
        minc = counter
        mini = i

print(min(mini, maxi)+2, max(mini, maxi)+1)
