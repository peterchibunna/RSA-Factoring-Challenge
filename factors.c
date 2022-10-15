#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

long long *factorize(long n)
{
	long i;
	static long long r[2];

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			r[0] = i;
			r[1] = n / i;
			return (r);
		}
	}

	r[0] = 1;
	r[1] = n;
	return (r);
}


int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL, *ptr;
	size_t len = 0;
	ssize_t read;
	long long *factors, number;

	(void) factors;

	if (argc != 2)
	{
		printf("Usage: %s <file>", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	factors = factorize(4);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		number = strtoll(line, &ptr, 10);
		factors = factorize(number);

		printf("%lld=%lld*%lld\n", number, factors[0], factors[1]);
	}

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
