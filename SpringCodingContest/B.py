N = int(input())
for i in range(N):
    income = int(input())
    x = income
    tax = 0
    if x > 10000:
        if x > 20000:
            tax += 1000
            if x > 40000:
                tax += .2*20000
                if x > 80000:
                    tax += .4*40000
                    tax += .8*(x-80000)
                else:
                    tax += .4*(x-40000)
            else:
                tax += .2*(x-20000)
        else:
            tax += .1*(x-10000)

    diff = int(tax - .5*income)

    if diff == 0:
        print('Clear')
    elif diff > 0:
        print('Owe',diff)
    else:
        print('Refund',-diff)
