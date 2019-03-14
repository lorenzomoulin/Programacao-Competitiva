command = input()
shelve = []
while command != "END":
	t = command.split(" by ")
	t[0] = t[0].strip('\"')
	shelve += [tuple(t)]
	command = input()		
shelve = sorted(shelve, key=lambda k: [k[1], k[0]])
borrowed = []
returned = []
command = input()
while command != "END":
	t = command.split("\"")
	if command[0] == "SHELVE":

	if command[0] == "BORROW ":

	if command[0] == "RETURN ":
