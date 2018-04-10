from math import sin,cos
pi = 3.14159265358
T = int(input())
for t in range(T):
    i,j,k = [ a for a in input().split() ]
    theta = float(k)/180*pi
    x = float(i)
    y = float(j)
    print('{0:.2f} {1:.2f}'.format(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta)))

