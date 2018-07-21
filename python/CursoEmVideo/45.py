from random import randint
from time import sleep

op = ('PEDRA','PAPEL','TESOURA')

print('{:=^30}'.format('(*-*) HORA DE JOGAR!'))



print(''' ESCOLHE LOGO!
[0] - PEDRA!
[1] - PAPEL!
[2] - TESOURA!''')
player = int(input())



if player in (0,1,2):

    pc = randint(0,2)

    print('{:=^40}'.format('='))
    print('PC = {}\nPLAYER = {}'.format(op[pc],op[player]))
    print('{:=^40}'.format('='))

    if (pc == 0 and player == 2) or (pc == 1 and player == 0) or (pc == 2 and player == 1):
        print('I WIN !!!! \(^.^)/')
    elif (player == 0 and pc == 2) or (player == 1 and pc == 0) or (player == 2 and pc == 1):
        print('I LOSE ! ,(;-;),')
    else :
        print('GOOD PLAY! `(0-0) ')
else :
    print('número INVALIDO !')
