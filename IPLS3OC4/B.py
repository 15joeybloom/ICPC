n = int(input())
bits = input()

counter = 1
i = 0
while i < n-1  and bits[i] == '1':
    counter += 1
    i += 1

print(counter)
