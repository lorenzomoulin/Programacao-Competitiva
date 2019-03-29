while True:
	n = int(input())
	if n == 0:
		break
	pilha = []
	for i in range(n, 0, -1):
		pilha.append(i)
	print("Discarded cards: " + str(pilha[-1]), end='')
	pilha.pop()
	pilha = [pilha[-1]] + pilha
	pilha.pop()
	while len(pilha) > 1:
		print(", " + str(pilha[-1]), end='')
		pilha.pop()
		pilha = [pilha[-1]] + pilha
		pilha.pop()
	print("\nRemaining card: " + str(pilha[0]))
