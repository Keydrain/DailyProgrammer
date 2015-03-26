#!/usr/bin/python3

"""
Solution for Easy Challenge #3
Author: Keydrain
Date:   03/26/15
"""

def ceaser(char_in, offset):
	loweralph = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	upperalph = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	
	try:
		if (char_in.istitle()):
			working = upperalph.index(char_in)
			working += offset
			if (working > len(upperalph)):
				working = working-len(upperalph)
			return upperalph[working]
		else:
			working = loweralph.index(char_in)
			working += offset
			if (working > len(loweralph)):
				working = working-len(loweralph)
			return loweralph[working]
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
	shift = input("Please enter offset to shift by. (~ will try all shifts): ")
	if (shift == '~'):
		for x in range(0,26):
			string = str(x) + ": "
			print("%4s" % string, end="")
			for char in sent:
				print(ceaser(char, -int(x)), end="")
			print("")
	else:
		for char in sent:
			print(ceaser(char, -int(shift)), end="")
print("")