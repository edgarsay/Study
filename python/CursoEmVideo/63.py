n = int(input('QUANTOS ELEMENTOS DA SEQUANCIA DE FIBONACCI VOCÊ QUER :'))

cont = 0
atual = 1
anterior = 0
print('{}'.format(anterior),end = '')

while cont < n - 1:
    cont +=1
    print('->{}'.format(atual),end = '')
    atemp = atual
    atual = atual + anterior
    anterior = atemp
print('')
