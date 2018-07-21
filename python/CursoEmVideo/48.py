print('SOMANDO TODOS OS NÚMEROS IMPARES MULTIPLOS DE 3 ENTRE 1 E 500')

count = 0

for i in range(1,501):
    if(i % 2 != 0):
        if(i % 3 == 0):
            count += 1

print('RESULTADO : {:*^10}'.format(count))
