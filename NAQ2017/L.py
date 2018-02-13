import math

d,s = [int(a) for a in input().split()]

def f(a):
    return a + s - a * math.cosh(d/(2*a))

low = 0
high = 1e9
eps = 1e-10
while math.fabs(high-low) > eps:
    mid = (high+low)/2
    fmid = f(mid)
    if fmid < 0:
        low = mid
    else:
        high = mid

print(2*mid*math.sinh(d/(2*mid)))
