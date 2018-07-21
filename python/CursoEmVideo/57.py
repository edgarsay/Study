sexo = ' '

sexo = input('Digite o seu sexo [M/F]: ').strip().upper()

while sexo != 'M' and sexo != 'F':
    print('UM CARACTER É INVALIDO!')
    sexo = input('Digite o seu sexo [M/F]: ').strip().upper()

print('O SEXO QUE VOCÊ DIGITOU FOI: {}'.format(sexo))
