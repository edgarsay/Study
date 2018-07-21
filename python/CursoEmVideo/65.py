op = 'Y'
cont = 1
soma = 0
while op == 'Y':
    n = int(input('DIGITE UM NUMERO INTEIRO :'))
    soma += n
    if cont == 1 :
        menor = n
        maior = n
    if n < menor:
        menor = n
    if n > maior:
        maior = n
    op = input('DIGITE "Y" PARA CONTINUAR OU QUALQUER OUTRA COISA PARA PARAR :').strip().upper()
    cont += 1
cont -= 1
media = soma / cont

print('VOCÊ DIGITO {} NUMEROS\nO MAIOR NUMERO FOI : {}\nO MENOR NUMERO FOI : {:.2f}\nA MEDIA DO NUMERO FOI: {}\n'.format(cont,maior,menor,media))
