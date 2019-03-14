n = int(input())
s = list(input())
i = s.index(max(s))
s1 = s[1:len(s)]
s2 = s[0:i] + s[i+1:len(s)]
s1 = ''.join(s1)
s2 = ''.join(s2)
if s1 < s2:
    print(s1)
else:
    print(s2)
