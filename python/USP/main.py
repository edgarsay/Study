import ordena
from random import randint
import time

inicio = time.time()
lista = []

for i in range(0,1000):
    lista.append(randint(1,1001))

ordena.ordena(lista)

fin = time.time()
print(fin-inicio)