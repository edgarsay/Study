import re

def cadastra (nomes):
    nome = str(input("cadastro:"))
    nomes.append(nome)
    print("")
def mostra (nomes):
    for i in nomes:
        print(i)

        #INCOMPLETO
def search(nomes):
    search = input("search: ")
    for i in nomes:
        f = re.findall('\w+?'+search+'\w+?',i)
        if f:
            print(f)

def menu (nomes):
    controle = 1
    while controle != 0:
        controle = input("Digite:\n[0-sair][1-cadastrar][2-mostrar][3-search]\n").strip()
        if controle == '0':
            return
        elif controle == '1':
            cadastra(nomes)
        elif controle == '2':
            mostra(nomes)
        elif controle == '3':
            #search(nomes)
        else :
            print("OPÇÃO INVALIDA")


