#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *ptr;
	
	__uint128_t number = 18446744073709551615903;

	/*number = strtoull("18446744073709551615903", &ptr, 10);*/
	/*number = atoll("18446744073709551615903");*/
	print(*(__uint128_t*)number);

	exit(EXIT_SUCCESS);
}