#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	FILE *p;
	int i;
	if((p = fopen("dados.txt", "w")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	for(i = 1; i <= 100; i++)
		fprintf(p, "%d\n", i);
	fclose(p);
}
