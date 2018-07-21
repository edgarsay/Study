def ordena(lista):
    i = 0
    previous,current = lista[0],lista[0]
    while 1:
        previous = current
        current = lista[i]
        if current < previous:
            lista[i],lista[i-1] = lista[i-1],lista[i]
            previous,current = lista[0],lista[0]
            i = 0
        i+=1
        if i == len(lista):
            break
    return lista

def bolha(lista):
    for i in range(len(lista)-1,0,-1):
        for j in range(i):
            if lista[j]>lista[j+1]:
                lista[j],lista[j+1] = lista[j+1],lista[j]
