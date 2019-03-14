ent = input()
ent = ent.split()

for j in range(len(ent)):
    for i in range(len(ent[j])):
        if i % 2 == 1:
            print(ent[j][i], end='')
    if j < len(ent) - 1:
        print(' ', end='')
print() 
