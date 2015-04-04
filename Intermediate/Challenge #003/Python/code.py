#!/usr/bin/python3

"""
Solution for Intermediate Challenge #3
Author: Keydrain
Date:   03/29/15

Uses qwerty to dvorak mappings plus offset to encode/decode. 

Note: Includes extra credit support of special symbols.
"""

qwerty = [' ','`','1','2','3','4','5','6','7','8','9','0','-','=','q','w','e','r','t','y','u','i','o','p','[',']','\\','a','s','d','f','g','h','j','k','l',';','\'','z','x','c','v','b','n','m',',','.','/','~','!','@','#','$','%','^','&','*','(',')','_','+','Q','W','E','R','T','Y','U','I','O','P','{','}','|','A','S','D','F','G','H','J','K','L',':','\"','Z','X','C','V','B','N','M','<','>','?']
dvorak = [' ','`','1','2','3','4','5','6','7','8','9','0','[',']','\'',',','.','p','y','f','g','c','r','l','/','=','\\','a','o','e','u','i','d','h','t','n','s','-',';','q','j','k','x','b','m','w','v','z','~','!','@','#','$','%','^','&','*','(',')','{','}','\"','<','>','P','Y','F','G','C','R','L','?','+','|','A','O','E','U','I','D','H','T','N','S','_',':','Q','J','K','X','B','M','W','V','Z']

def encode(char_in, offset):
	working = qwerty.index(char_in)
	working += offset
	while (working > len(qwerty)):
		working = working - len(qwerty)
	return dvorak[working]

def decode(char_in, offset):
	working = dvorak.index(char_in)
	working += offset
	while (working > len(dvorak)):
		working = working - len(dvorak)
	return qwerty[working]

choice = input("\nPlease make a selection:\n  1: Encrypt\n  2: Decrypt\n> ")
if (int(choice) == 1):
	sent = input("Please enter sentence to encrypt: ")
	shift = input("Please enter offset to shift by: ")
	for char in sent:
		print(encode(char, int(shift)), end="")
elif (int(choice) == 2):
	sent = input("Please enter sentence to decrypt: ")
	shift = input("Please enter offset to shift by. (~ will try all shifts): ")
	if (shift == '~'):
		for x in range(0,26):
			string = str(x) + ": "
			print("%4s" % string, end="")
			for char in sent:
				print(decode(char, -int(x)), end="")
			print("")
	else:
		for char in sent:
			print(decode(char, -int(shift)), end="")
print("\n")