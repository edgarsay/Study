numero = 0
cont = 0
soma = 0
while numero != 999:
    soma += numero
    numero = float(input('numero :'))
    cont += 1

print('VOCÊ DIGITOU {} NÚMEROS\nE A SOMA DELE É {}\n'.format(cont-1,soma))
