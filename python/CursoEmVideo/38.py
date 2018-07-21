n1 = float(input('digite o primero numero :'))
n2 = float(input('digite o segundo numero :'))

if n1 > n2:
    print('{:.0f} é o maior numero!'.format(n1))
elif n2 >n1:
    print('{:.0f} é o maior numero!'.format(n2))
else :
    print('Não existe valor maior, os dois são iguais')