#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	FILE *p;
	char c;
	if((p = fopen("dados.txt", "r")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	while(!feof(p))
	{
		c = getc(p);
		printf("%c", c);
	}
	fclose(p);
}
