from random import randint

print('VOU PENSAR NUM NÚMERO DE ENTRE 0 E 10\nTENTE ADIVINHAR QUAL...')

pc = randint(0,10)

player = -1

tentativas = 0

while player != pc :
    tentativas += 1
    if tentativas == 1 :
        player = int(input('ESCOLHA UM NUMERO :'))
    else :
        player = int(input('VOCÊ ERROU!\nTENTE MAIS UMA VEZ :'))

print('VOCÊ ACERTOU EM {} tentativas!'.format(tentativas))
