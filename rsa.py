#!/usr/bin/python3
import sys
from math import sqrt


def is_prime(n):
	flag = 1
	for i in range(2, int(sqrt(n))):
		#/* If n is divisible by any number between*/
		#/* 2 and n/2, it is not prime*/
		if n % i == 0:
			flag = 0
			break

	if n <= 1:
		flag = 0

	return (flag)


def factorize(number):
	for i in range(2, number):
		if number % i == 0:
			if is_prime(i) and is_prime(int(number / i)):
				print("{:d}={:d}*{:d}".format(number, int(number / i), i))
				return
	print("{:d}={:d}*{:d}".format(number, number, 1))


if __name__ == "__main__":
	if len(sys.argv) == 2:
		filename = sys.argv[1]
		with open(filename, 'r') as file:
			for line in file.readlines():
				try:
					num = int(line.strip())
					factorize(num)
				except:
					pass
	else:
		sys.exit("Usage: {} <file>".format(sys.argv[0]))
