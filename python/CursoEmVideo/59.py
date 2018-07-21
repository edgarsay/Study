
o = -1
while(o != 0):
    n1 = float(input('DIGITE O PRIMEIRO VALOR: '))
    n2 = float(input('DIGITE O PRIMEIRO VALOR: '))

    o = int(input('[ 1 ] somar\n[ 2 ] multiplicar\n[ 3 ] maior\n[ 4 ] novos números\n[ 5 ] sair do programa\n'))
    if (o == 1):
        print('soma {:.2f}'.format(n1 + n2))
    elif(o == 2):
        print('multiplição {:.2f}'.format(n1 * n2))
    elif(o == 3):
        if(n1 > n2):
            print('maior',n1)
        else:
            print('maior',n2)
    elif(o == 4):
        print('informe novamente os numeros...')
    elif(o == 5):
        print('PROGRAMA FINALIZADO...')
        break
    else :
        print('OPÇÃO INVALIDA!')
