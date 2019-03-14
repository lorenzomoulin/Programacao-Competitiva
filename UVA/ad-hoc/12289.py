n =int(input())

while n > 0:
    s = input()
    if len(s) == 3:
        if s[1:3] == 'ne':
            print ('1')
        elif s[0:2] == 'on':
            print('1')
        elif s[0] == 'o' and s[2] == 'e':
            print('1')
        elif s[1:3] == 'wo':
            print('2')
        elif s[0:2] == 'tw':
            print('2')
        elif s[0] == 't' and s[2] == 'o':
            print('2')
    else:
        print('3')
           
    n -= 1
