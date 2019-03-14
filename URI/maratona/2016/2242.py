r = input()
r = list(r)
v = [x for x in r if x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u']
if v == v[::-1]:
    print("S")
else:
    print("N")
