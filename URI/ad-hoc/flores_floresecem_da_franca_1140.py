while True:
    s = input()
    if s == "*":
        break
    s = s.split()
    e = s[0][0]
    t = True
    for i in s:
        if i.lower()[0] != e and i.upper()[0] != e:
            t = False
            break
    if t:   
        print("Y")
    else:
        print("N")
