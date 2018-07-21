print('digite a idade de 7 pessoas:')

pmenores = 0

pmaiores = 0

for i in range(0,7):
    p = int(input('idade da {}ª pessoa:'.format(i+1)))
    if p > 17:
        pmaiores += 1
    else:
        pmenores += 1

print('DAS 7 PESSOAS {} SÃO MAIORES DE IDADE!\nE {} SÃO MENORES!'.format(pmaiores,pmenores))
