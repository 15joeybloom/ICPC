n,m = [ int(a) for a in input().split() ]

def pairs(x):
    return (x*(x-1))//2

minfriends = pairs(n//m)*(m-n%m) + pairs(n//m+1)*(n%m)
maxfriends = pairs(n-m+1)

print(minfriends,maxfriends)
