p = float(input('DIGITE O PRIMEIRO TERMO DA PA :'))
r = float(input('DIGITE A RAZÃO DA PA :'))

cont = 1
ate = 10

while cont <= ate:
    print('{}º TERMO: {}'.format(cont,p));
    cont += 1
    p = p + r
    if(cont > ate):
        ate += float(input('VOCÉ DESEJA VER MAIS TERMOS?\nQUANTOS:'))
