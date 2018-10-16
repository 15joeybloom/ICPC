N = int(input())
day = []
sunrise = []
sunset = []
for _ in range(N):
    H, R, T = [ int(a) for a in input().split() ]
    day.append(H)
    sunrise.append(R)
    sunset.append(T)


