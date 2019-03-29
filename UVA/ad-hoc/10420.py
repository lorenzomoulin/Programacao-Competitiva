n = int(input())
paises = dict()
for i in range(n):
	linha = input().split()
	if paises.__contains__(linha[0]):
		paises[linha[0]] += 1
	else:
	 	paises[linha[0]] = 1
dic = dict(sorted(paises.items()))
for k in dic:
	print(k, dic[k])
