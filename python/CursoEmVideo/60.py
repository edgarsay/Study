n = int(input('DIGITIE UM NUMERO :'))
n1 = n
FATORIAL = 1;

if n == 0:
    print('O FATORIAL DE 0 É 1!')
elif n < 0:
    print('NÃO HÁ FATORIAL DE NÚMERO NEGATIVO...')
else :
    while n > 0:
        FATORIAL *= n
        n = n - 1

    print('FATORIAL DE {} É {}!'.format(n1,FATORIAL))
