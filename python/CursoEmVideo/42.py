l1 = float(input('digite o primeiro lado do triangulo :'))
l2 = float(input('digite o segundo lado do triangulo :'))
l3 = float(input('digite o terçeiro lado do triangulo :'))

print('\nO triangulo te lados de tamanho {:.0f}, {:.0f} e {:.0f}'.format(l1,l2,l3))

if l1 > (l2 + l3) or l2 > (l1 + l3) or l3 > (l2 + l1):
    print('Não foi possivel formar um triangulo! ;-;')
elif  l1 == l2 and l1 == l3:
    print('Como os três lados do triangulos são iguais, esse triangulo é EQUILÁTERO!')
elif (l1 == l2 and l1 != l3) or (l2 == l3 and l2 != l1) or (l3 == l1 and l3 != l2):
    print('Como dois lados são iguais, esse é um triangulo ISÓSCELES!')
else:
    print('Como todos os lados são difirentes, esse é um triangulo ESCALENO!')
