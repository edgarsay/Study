valor = float(input('Valor R$'))
salario = float(input('Salario R$'))
anos = int(input('Numero de ano para pagar :'))

tempo = anos * 12

prestação = valor / tempo

if prestação > (salario*30/100):
    print('Emprestimo negado!')
else:
    print('Emprestimo aceito!')
