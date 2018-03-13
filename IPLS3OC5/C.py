n = int(input())
letters = [ int(a) for a in input().split() ]

unread = 0
changes = 0
last = 0
for letter in letters:
    if letter == 1:
        unread += 1

    if last != letter:
        last = letter
        changes += 1

if letters[0] == 0 and changes > 0:
    changes -= 1
if letters[n-1] == 0 and changes > 0:
    changes -= 1
print(unread + changes//2)

