file_in = open("zeros.in", "r")

t = int(file_in.readline())
while t > 0:
    x, y, m, k = [int(n) for n in file_in.readline().split()]

    num = []

    for i in range(0, x):
        num.append(1)

    for j in range(x, x + y):
        num.append(0)
    n = 0
    cont = 0
    for s in range(0, x + y):
        if num[s] == 1:
            n += pow(2, x + y - s - 1)
    if n % m >= k:
        cont += 1
    for i in range(x - 1, 0, -1):
        for j in range(i, i + y):
            num[j], num[j + 1] = num[j + 1], num[j]
            n = 0
            for s in range(0, x + y):
                if num[s] == 1:
                    n += pow(2, x + y - s - 1)
            if n % m >= k:
                cont += 1    
    print(cont)
    t -= 1
