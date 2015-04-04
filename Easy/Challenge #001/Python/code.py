#!/usr/bin/python3

"""
Solution for Easy Challenge #001
Author: Keydrain
Date:   03/25/15

Includes 'Extra Credit' file management
Once the out.log file has been created, it must be deleted to be changed. 
"""

import sys

FILE = "out.log"
try:
	f = open(FILE, 'r')
	print(f.read())
except:
	f = open(FILE, 'w+')
	name = input("Please enter your name: ")
	age = input("Please enter your age: ")
	username = input("Please enter your reddit username: ") 
	print("Your name is %s, you are %s years old, and your username is %s\n" % (name, age, username))
	f.write("Your name is %s, you are %s years old, and your username is %s\n" % (name, age, username))