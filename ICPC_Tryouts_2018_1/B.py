runners = []
n = int(input())
for i in range(n):
    a,b,c = input().split()
    runners.append((a, float(b), float(c)))

bestt = 999999999
bestteam = []
for first_runner, first_lap_time, _ in runners:
    others = sorted([x for x in runners if x[0] != first_runner], key=lambda x: x[2])[:3]

    time = first_lap_time + sum([x[2] for x in others])
    if time < bestt:
        bestt = time
        bestteam = [first_runner] + [x[0] for x in others]

print(bestt)
for x in bestteam:
    print(x)

