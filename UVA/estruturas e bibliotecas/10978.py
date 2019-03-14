while True:
	n = int(input())
	if n == 0:
		break
	nome = []
	extenso = []
	res = ["" for x in range(n)]
	visited = [False for x in range(n)]
	for i in range(n):
		s = input().split()
		nome.append(s[0])

		extenso.append(s[1])
		#print(nome[i] + " " + extenso[i])

	pos = 0
	for i in range(n):
		cont = 0
		while cont < len(extenso[i]):
			if pos == n:
				pos = 0
			if visited[pos] == False:
				cont += 1
			pos += 1
	
		visited[pos - 1] = True
		res[pos - 1] = nome[i]
	for i in range(n - 1):
		print(res[i], end=' ')
	print(res[-1])
