numero = int(input('digite um numero :'))

for i in range(numero-1,0,-1):
    if i == 1:
        print('O numero {} é um numero IMPAR!'.format(numero))
        break
    if numero % i == 0:
        print('O numero {} é divisivel por {}. logo NÃO é um numero IMPAR!'.format(numero,i))
        break
