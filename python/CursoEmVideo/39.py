from datetime import date

nacido = int(input('digite o ano em que nacel: '))
sexo = input('digite "M" se você for do sexo masculino e "F" se for do sexo feminino :').strip().upper()

if sexo == 'M':
    ano = (date.today().year)
    idade = ano - nacido

    if idade == 18:
        print('Você deve se alistar imediatament')
    elif idade > 18:
        alistamento = idade - 18
        print('Você deveria ter se alistado há {} anos atraz, em {}'.format(alistamento,ano - alistamento))
    else :
        alistamento = 18 - idade
        print('Você tera que se alistar daqui há {} anos'.format(alistamento, ano + alistamento))
else :
    print('O alistamento militar é obrigatorio apenas para o sexo masculino!')
    print('Você não precisa se alistar')