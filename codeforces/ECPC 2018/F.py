M = open("mosalah.in", "r")

t = int(M.readline())

while t > 0:
    n, m, x, y = M.readline().split()
    n = int(n)
    m = int(m)
    x = int(x)
    y = int(y)
    k = n*(x + y) - m
    if k > 0 and m < 1:
        print(-1)
    else:
        print(k)
    #print((m + k)/(x + y))
    t -= 1
M.close()
