import sys

print('a'*100000)
print(10**4)

chars = ['a','b','c','d','e']
printed = 0
for i1 in chars:
    for i2 in chars:
        for i3 in chars:
            for i4 in chars:
                for i5 in chars:
                    for i6 in chars:
                        print(i1+i2+i3+i4+i5+i6)
                        printed += 1
                        if printed == 10**4:
                            sys.exit()
