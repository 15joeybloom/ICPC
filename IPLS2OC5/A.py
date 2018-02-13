n = int(input())

a = [int(a) for a in input().split()]

sum = 0
for x in a:
    sum += x

print(len([a for a in a if a % 2 == sum % 2]))
