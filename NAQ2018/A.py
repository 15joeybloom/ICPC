n = int(input())
cards = []
for _ in range(n):
    card = set()
    for _ in range(5):
        card = card.union([int(a) for a in input().split() ])
    cards.append(card)
tiers = []
for i in range (1, 3001):
    temp = []
    for j in range(n):
        if i in cards[j]:
            temp.append(j+1)
    if len(temp) >= 2 and (tiers == [] or temp[:2] < tiers):
        tiers = temp[:2]

if tiers:
    print(tiers[0], tiers[1])
else:
    print('no ties')

