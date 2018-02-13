prog = input()
good = False
for c in prog:
    if c in ['H', 'Q', '9']:
        good = True
if good:
    print('YES')
else:
    print('NO')
