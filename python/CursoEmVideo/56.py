print('DIGITE O NOME, SEXO ("M" OU "F") E IDADE DE 5 PESSOAS:')

Mmaisvelho = 0
Nmaisvelho = ''
contMmenos20 = 0
idades = 0

for i in range(0,4):
    print('{:=^40}'.format('{}ªPESSOA'.format(i+1)))
    nome = input('NOME :'.format(i+1)).strip()
    idade = int(input('IDADE :'.format(i+1)))
    sexo = input('SEXO[F/M] :'.format(i+1)).strip().upper()

    if sexo == 'M' and idade > Mmaisvelho :
        Mmaisvelho = idade
        Nmaisvelho = nome
    
    if sexo == 'F' and idade < 20 :
        contMmenos20 += 1

    idades += idade 
print('''{} É O HOMEM MAIS VELHO DESSE GRUPO!
HÁ {} MULHER COM IDADE MENOR QUE 20 ANOS!
A MEDIA DE IDADE DE GRUPO É  {:.2f}'''.format(Nmaisvelho,contMmenos20,idades / 4))
    

