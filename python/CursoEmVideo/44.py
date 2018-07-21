print('{:=^50}'.format('!ISADORA PINTO!'))

valor = float(input('digite o valor do produto R$'))

pagamento = int(input('''[1] - à vista dinheiro/cheque: 10 por cento de desconto 
[2] - à vista no cartão: 5 por cento de desconto 
[3] - em até 2x no cartão: preço formal 
[4] - 3x ou mais no cartão: 20 por cento de juros :'''))

if pagamento == 1 :
    print('O valor a pagar é de  R${:.2f}'.format(valor - valor/10))
elif pagamento == 2 :
    print('O valor a pagar é de  R${:.2f}'.format(valor - valor/20))
elif pagamento == 3 :
    print('O valor a pagar é de  R${:.2f}'.format(valor))
elif pagamento == 4:
    print('O valor a pagar é de  R${:.2f}'.format(valor + valor/5))
else :
    print('forma de pagamento invalida!')
