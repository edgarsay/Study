p = float(input('DIGITE O PRIMEIRO TERMO :'))
r = float(input('DIGITE A RAZÃO :'))

cont = 1
while cont <= 10:
    print('{}º termo: {}'.format(cont,p))
    cont += 1
    p = p + r
