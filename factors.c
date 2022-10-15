#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void *factorize(unsigned long long int n)
{
	unsigned long i;
	/*static unsigned long r[2];*/
	/*(void)r;*/
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			printf("%llu=%lu*%lu\n", n, (unsigned long)n / i, (unsigned long)i);
			return (0);
		}
	}

	printf("%llu=%lu*%lu\n", n, (unsigned long)n, (unsigned long)1);
	return (0);
}


int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL, *ptr;
	size_t len = 0;
	ssize_t read;
	unsigned long *factors;
	unsigned long long int number;

	(void) factors;
	(void) ptr;

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
		factorize(strtoull(line, &ptr, 10));
	}

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
