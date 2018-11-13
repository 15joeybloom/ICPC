n, m = [ int(x) for x in input().split() ]
a = [ int(x) for x in input().split() ]

freq = [ 0 for _ in range(110) ]
for food in a:
    freq[food] += 1

def canfeeddays(days):
    people = 0
    for food in freq:
        people += food // days
    return people

days = 0
while canfeeddays(days+1) >= n:
    days += 1

print(days)
