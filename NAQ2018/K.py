task, s = input().split()
if task == 'D':
    decoded = ''
    i = 0
    while i < len(s):
        decoded += s[i]*int(s[i+1])
        i += 2
    print(decoded)
else:
    encoded = ''
    last = s[0]
    count = 1
    i = 1
    while i < len(s):
        if s[i] == last:
            count += 1
        else:
            encoded += last + str(count)
            count = 1
            last = s[i]
        i += 1
    encoded += last + str(count)
    print(encoded)
