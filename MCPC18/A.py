# Author: Andrew Hsu

S = int(input().strip())
print('{0}:'.format(S))

for i in range(2, S // 2 + 2):
    s1 = 2 * i - 1
    if S % s1 == 0 or S % s1 == i:
        print('{0},{1}'.format(i, i - 1))

    s2 = s1 + 1
    if S % s2 == 0 or S % s2 == i:
        print('{0},{1}'.format(i, i))
