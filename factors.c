#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/*unsigned long long*/
void *factorize(unsigned long long n)
{
	unsigned long long i;
	static unsigned long long r[2];

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			r[1] = (unsigned long long)i;
			r[0] = (unsigned long long)n / i;
			/*printf("%llu=%llu*%llu\n", n, 
			(unsigned long long)n / i, (unsigned long long)i);
			return (0);*/
			return (r);
		}
	}

	r[1] = (unsigned long long)1;
	r[0] = (unsigned long long)n;
	/*printf("%llu=%llu*%d\n", n, (unsigned long long)n, 1);
	return (0);*/
	return (r);
}


int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL, *ptr;
	size_t len = 0;
	ssize_t read;
	unsigned long long *factors;
	unsigned long long number;

	(void) factors;

	if (argc != 2)
	{
		printf("Usage: %s <file>", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		number = strtoull(line, &ptr, 10);

		/*factorize(number);*/
		factors = factorize(number);
		printf("%llu=%llu*%llu\n", number, factors[0], factors[1]);
	}

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
