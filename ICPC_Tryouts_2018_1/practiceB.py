try:
    while True:
        line = input()
        if 'problem' in line.lower():
            print('yes')
        else:
            print('no')
except EOFError:
    pass
