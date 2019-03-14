data = {'HELLO': 'ENGLISH', 'HOLA':'SPANISH', 'HALLO':'GERMAN', 'BONJOUR':'FRENCH', 'CIAO':'ITALIAN', 'ZDRAVSTVUJTE':'RUSSIAN'}
cases = 1
while True:
    s = input()
    if s == "#":
        break
    if data.__contains__(s):
        print('Case ' + str(cases) + ': ' + data[s])
    else:
        print('Case ' + str(cases) + ': UNKNOWN')
    cases += 1
