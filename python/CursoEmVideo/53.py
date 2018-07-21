frase = input('digite uma frase :').strip().lower()
frase = frase.split()
frase = ''.join(frase)

tamanho = (len(frase)-1)

r = ''

for i in range(tamanho,-1,-1):
    r += frase[i]

if r == frase:
    print('ESSA FRASE É ALINDROMA!')
else :
    print('ESSA FRASE NÃO É ALINDROMA!')