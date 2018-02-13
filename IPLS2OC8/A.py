n = int(input())
counter = 0
alcohols = ['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
for i in range(n):
    line = input()
    if line in alcohols:
        counter += 1
    else:
        try:
            if int(line) < 18:
                counter += 1
        except ValueError:
            pass

print(counter)
