def bs(a, l, r, v):
    mid = l + (r - l)//2
    if l > r:
        return -1
    if a[mid] == v:
        return mid
    idx = 0
    if v > a[mid]:
        idx = bs(a, mid + 1, r, v)
    if v < a[mid]:
        idx = bs(a, l, mid - 1, v)
    return idx

n = int(input())
soma = 0
a = []

for i in input().split():
    j = int(i)
    a.append(j)
    soma += j
c = [x for x in a]    
a.sort()
j = []
num = 0

for i in range(0, len(a)):
    b = a[0:i] + a[i+1:len(a)]
    
    idx = bs(b, 0, len(a) - 2, (soma - a[i])//2)
    if idx != -1 and b[idx]*2 == (soma - a[i]):
        idx2 = [k for k, val in enumerate(c) if val == a[i]]
        
        if j.__contains__(idx2) == False: 
            j.append(idx2)
         
for i in j:
    num += len(i)
print(num)    
for i in j:
    for k in range(0, len(i)):
        if i == j[len(j) - 1] and k == len(i) - 1:
            print(i[k] + 1, end='')
        else:
            print(i[k] + 1, end=' ')
print()
