print('DIGITE O PESO DE 5 PESSOAS')

maior = 0
menor = 0

for i in range(0,5):
    p = float(input('digite o peso da {}ª pessoa :'.format(i+1)))
    if i == 0 :
        maior = p
        menor = p

    if p > maior :
        maior = p

    if p < menor :
        menor = p

print('{:.2f} é o MENOR peso!\n{:.2f} é o MAIOR peso!'.format(menor,maior))

