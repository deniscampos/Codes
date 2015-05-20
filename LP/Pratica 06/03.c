#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	FILE *p;
	char c, str[150];
	if((p = fopen("03.c", "r")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	while(!feof(p)){
		if(fgets(str, 150, p) != NULL) {
			printf("%s", str);
		}
	}

	fclose(p);
}
