n1 = float(input('digite a primeira nota :'))
n2 = float(input('digite a segunda nota :'))

media = (n1 + n2) / 2

if media >= 7 :
    print('Parabens, Você for aprovado!')
elif media >=5 and media < 7 :
    print('Você podera que fazer a recuperação')
else :
    print('Você for reprovado! ;-;')
