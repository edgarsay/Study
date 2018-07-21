from datetime import date

nascer = int(input('digite o ano de nacimento do participante :'))

atual = date.today().year

idade = atual - nascer

print('O atleta tem {} anos'.format(idade))

if idade <= 9 :
    print('Esse participante esta classificado como "MIRIM"')
elif idade > 9 and idade <=14:
    print('Esse participante esta classificado como "INFANTIL"')
elif idade > 14 and idade <=19:
    print('Esse participante esta classificado como "JÚNIOR"')
elif idade > 19 and idade <=25:
    print('Esse participante esta classificado como "SÉNIOR"')
elif idade > 25 :
    print('Esse participante esta classificado como "MASTER"')
