# Author: Andrew Hsu

line = input().strip()

words = line.split()
words_lower = list(map(lambda w: w.lower(), words))
alphabet = set(c for c in 'abcdefghijklmnopqrstuvwxyz')
vowels = set(['a', 'e', 'i', 'o', 'u', 'y'])

for i, word in enumerate(words_lower):
    j = 0
    while j < len(word):
        if word[j] not in alphabet:
            break
        j += 1
    words_lower[i] = word[:j]

def get_syllables(word, vowels):
    is_a_vowel = [False for i in range(len(word))]

    for i, c in enumerate(word):
        if c in vowels:
            if c == 'u':
                if i > 0 and word[i - 1] == 'q':
                    continue
            elif c == 'y':
                if i + 1 < len(word) and word[i + 1] in vowels and word[i + 1] != 'y':
                    continue
            elif c == 'e' and i == len(word) - 1:
                vowel = False
                if i > 0 and word[i - 1] == 'l':
                    if i - 1 > 0 and not is_a_vowel[i - 2]:
                        vowel = True
                if not vowel:
                    continue
            elif c == 'e' and i == len(word) - 2:
                vowel = True
                if word[i + 1] == 's':
                    vowel = False
                if i - 1 > 0:
                    if not is_a_vowel[i - 2] and not is_a_vowel[i - 1]:
                        if word[i - 1] == 'u':
                            if i - 2 > 0 and not is_a_vowel[i - 3]:
                                vowel = True
                        else:
                            vowel = True
                if not vowel:
                    continue
            is_a_vowel[i] = True

    syls = 0
    const = True

    for is_vowel in is_a_vowel:
        if is_vowel:
            if const:
                syls += 1
            const = False
        else:
            const = True

    return max(syls, 1)

line1 = []
line1_syls = 0
line2 = []
line2_syls = 0
line3 = []
line3_syls = 0

for i, word in enumerate(words_lower):
    syls = get_syllables(word, vowels)

    if line1_syls < 5:
        line1_syls += syls
        line1.append(words[i])
    elif line2_syls < 7:
        line2_syls += syls
        line2.append(words[i])
    else:
        line3_syls += syls
        line3.append(words[i])

if line1_syls == 5 and line2_syls == 7 and line3_syls == 5:
    print(' '.join(line1))
    print(' '.join(line2))
    print(' '.join(line3))
else:
    print(line)
