def mais_arestas(lista):
    pos_maior = 0 
    maior = 0
    #print(lista)
    for i in range(len(lista)):
        #print("len(lista) = " + str(len(lista[i])))
        #print("maior = " + str(maior))
        if int(len(lista[i])) > maior:
            pos_maior = i
            maior = len(lista[i])


    return pos_maior

def retira(lista, maior):
    for l in lista:
        for i in l:
            #print("i: " + str(i))
            #print("maior: " + str(maior))
            if i == maior:
                #print("entrou")
                l.remove(i)
    
    lista[maior] = []
   # print(lista)
    #print(lista[maior])
    return lista

def vazia(lista):
    for i in lista:
        if i != []:
            return False
    return True


t = int(input())
caso = 1
while t > 0:
    t -= 1

    inp = [int(x) for x in input().split()]
    n = inp[0]
    a = inp[1:len(inp)]

    inp = [int(x) for x in input().split()]
    m = inp[0]
    b = inp[1:len(inp)]
   
    #print(a)
    #print(b)
    grafo = [[] for x in range(n + m)]


    for i in range(n):
        for j in range(m):

            if (b[j] != 0) and (a[i] == 0):
              continue

            if b[j] == 0:
                grafo[i].append(j + n)
                grafo[n + j].append(i)

            elif b[j] % a[i] == 0:
                grafo[i].append(j + n)
                grafo[n + j].append(i)
            #print(grafo)

    #print(grafo)
    remocoes = 0
    while not vazia(grafo):
        #print(len(grafo))
       
        maior = mais_arestas(grafo)
        grafo = retira(grafo, maior)
        # if maior >= n:
        #     print("===========REMOVEU o " + str(b[maior - n]) + " ==========")
        # else:
        #     print("===========REMOVEU o " + str(a[maior]) + " ==========")
        # print(grafo)
        # print()
        remocoes += 1

        # if remocoes >= n or remocoes >= m:
            
        #     remocoes = min(n, m)
    
    print("Caso #" + str(caso) + ": " + str(remocoes))
    caso += 1