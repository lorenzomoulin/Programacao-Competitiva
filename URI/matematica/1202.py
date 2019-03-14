def mod_exp(a, b, m):
    if b == 0:
        return 1
    c = mod_exp(a, b // 2, m)
    c = (c * c) % m
    if b % 2 != 0:
        c = (c * a) % m
    return c
    
def func():
    s = input()
    num_mod = 0
    l = int(len(s)) - 1
    exp = 0
    for i in range(l, -1, -1):
        if int(s[i]) == 1:
            num_mod += (num_mod % 1500 +  ((int(s[i]))*mod_exp(2, exp , 1500)))%1500  
        exp += 1  
    print("%03d" % fib[num_mod])
    
n = int(input())

fib = [0, 1, 1]

for i in range(3, 1501):
    fib.append((fib[i - 1] % 1000 + fib[i - 2] % 1000) % 1000) 

while n > 0:
    n -= 1
    func()
