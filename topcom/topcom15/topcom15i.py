t = int(input())
while t > 0:
	t -= 1
	regras = ["" for x in range(256)]
	ordem = int(input())
	inicial = input()
	qnt_regras = int(input())
	for i in range(qnt_regras):
		variavel, regra = input().split('=')
		regras[ord(variavel)] = regra
	for i in range(ordem):
		temp = ""
		for j in range(len(inicial)):
			if regras[ord(inicial[j])] != '':
				temp += regras[ord(inicial[j])]
			else:
				temp += inicial[j]
		inicial = temp
	print(inicial)