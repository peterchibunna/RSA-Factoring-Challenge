#!/usr/bin/python3
import sys

# def factorize(num):
#     """ Generate 2 factors for a given number"""
#     factor1 = 2
#     while (num % factor1):
#         if (factor1 <= num):
#             factor1 += 1
#     factor2 = num // factor1
#     return [factor2, factor1]

def factorize(number):
	for i in range(2, number):
		if number % i == 0:
			print("{:d}={:d}*{:d}".format(number, int(number / i), i))
			break
# 			return [int(number / i), i]
	print("{:d}={:d}*{:d}".format(number, number, 1))
# 	return [int(number), 1]


if __name__ == "__main__":
	if len(sys.argv) == 2:
		filename = sys.argv[1]
		with open(filename, 'r') as file:
			for line in file.readlines():
				num = int(line.strip())
				factorize(abs(num))
# 				print(num < 0)
# 				factors = factorize(abs(num))
# 				print("{:d}={:d}*{:d}".format(num, factors[0], factors[1]))
	else:
		sys.exit("Usage: {} <file>".format(sys.argv[0]))
