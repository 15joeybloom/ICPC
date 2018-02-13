def matches(pattern, text):
    for i in range(len(text)-len(pattern), -1, -1):
        good = True
        for j in range(len(pattern)):
            if not text[i+j] in ['?', pattern[j]]:
                good = False
        if good:
            return i
    return -1

Sprime = input()
T = input()

match = matches(T, Sprime)
if match == -1:
    print('UNRESTORABLE')
else:
    print((Sprime[:match]+T+Sprime[match+len(T):]).replace('?','a'))
