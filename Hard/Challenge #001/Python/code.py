#!/usr/bin/python3

"""
Solution for Hard Challenge #1
Author: Keydrain
Date:   03/26/15 
"""

from random import randint

upper = 100
lower = 1
acceptable = {"low", "higher", "high", "lower", "yes"}

input("\nLets play a game! Think of a number. Press enter when ready.")
guess = randint(lower,upper)

while (True):
	if(lower == upper):
		break
	vote = input("Is it " + str(guess) + "? ")
	vote = vote.lower()
	if vote in acceptable:
		if (vote == "low" or vote == "higher"):
			lower = guess+1
			guess = randint(lower, upper)
		elif (vote == "high" or vote == "lower"):
			upper = guess-1
			guess = randint(lower, upper)
		if (vote == "yes"):
			break
	else:
		print("I don't understand, please try again. ")

print("The number is " + str(guess) + "\n")