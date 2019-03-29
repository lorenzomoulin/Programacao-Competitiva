t = int(input())

while t > 0:
    input()
    seq = input().split()
    a = [float(x) for x in input().split()]
    a.sort()
    print(a)
    for i in seq:
        print(a[int(i) - 1])
    print()
    t -= 1
