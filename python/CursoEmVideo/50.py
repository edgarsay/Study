n = []
for i in range(0,6):
    n.append(int(input('digito o {}º valor :'.format(i+1))))

soma = 0

for i in range(0,6):
    if(n[i] % 2 == 0):
        soma += n[i]

print('SOMA DE TODOS OS NUMEROS PARES = {}'.format(soma))
