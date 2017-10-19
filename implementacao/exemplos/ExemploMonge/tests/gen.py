#!/usr/bin/python3
import random

n = int(input())

print(str(random.randint(1,n)) + " " + str(n))
output = ""
for i in range(n):
	print(str(10000*random.random())),
