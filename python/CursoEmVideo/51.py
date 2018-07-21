primeiro = int(input('Digite o primeiro termo da PA :'))
razao = int(input('Agora digite a rasão de PA :'))

anterior = 0

print('termo {:2} : {:2}'.format(1,primeiro))

anterior = primeiro

for i in range(1,10):
    print('termo {:2} : {:2}'.format(i+1,anterior+razao))
    anterior = anterior+razao
