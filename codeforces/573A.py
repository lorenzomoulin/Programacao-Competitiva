n = int(input())
a = [int(x) for x in input().split()]

v = set()
for e in a:
    while e % 2 == 0:
        e = e // 2
    while e % 3 == 0:
        e = e // 3
    v.add(e)
if len(v) == 1:
    print("Yes")
else:
    print("No")
