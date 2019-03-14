from sys import stdin

for line in stdin:
    temp = ""
    ans = ""
    home = False
    for i in line:
        if i == '[':
            home = True
            continue
        if i == ']':
            home = False
            ans = temp + ans
            continue
        if home == True:
            temp += i
            
        else:
            ans = ans + i
    print(ans, end='')
