t = int(input())

for i in range(t):
    entrada = input()
    exclamacao = entrada.index("!")
    n = int(entrada[:exclamacao])
    k = int(len(entrada)) - exclamacao
    dif = n
    kfact = 1
    cont = 0
    while dif > 1:
        kfact *= dif
        cont += 1
        dif = n - cont*k
    print(kfact)
