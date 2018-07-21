numero = int(input('digite um numero inteiro :'))
base = int(input('digite 1 para binário, 2 para octal e 3 para hexadecimal.'))

if base == 1:
    print('{} em decimal é equivalente a {} em binario'.format(numero,bin(numero)[2:]))
elif base == 2:
    print('{} em decimal é equivalente a {} em octal'.format(numero,oct(numero)[2:]))
elif base == 3:
    print('{} em decimal é equivalente a {} em hexadecimal'.format(numero,hex(numero)[2:]))