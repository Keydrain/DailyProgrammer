#!/usr/bin/python3

def ceaser(char_in, offset):
	alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	try:
		working = alphabet.index(char_in)
		working += offset
		if (working > len(alphabet)):
			working = working-len(alphabet)
		working = alphabet[working]
		return working
	except:
		return char_in

choice = input("Please make a selection:\n  1: Encrypt\n  2: Decrypt\n> ")
if (int(choice) == 1):
	sent = input("Please enter sentence to encrypt: ")
	shift = input("Please enter offset to shift by: ")
	for char in sent:
		print(ceaser(char, int(shift)), end="")
elif (int(choice) == 2):
	sent = input("Please enter sentence to decrypt: ")
	shift = input("Please enter offset to shift by: ")
	for char in sent:
		print(ceaser(char, -int(shift)), end="")
print("")