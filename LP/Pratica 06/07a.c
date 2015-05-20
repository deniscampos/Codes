#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void cripto(char * c, int * ok){
	if(* ok % 2 == 0)
		* c += 7;
	else
		* c += 3;
	ok++;
}

int main()
{
	FILE *arq1, *arq2;
	int i, tam, ok = 0;
	char c;
	
	if((arq1 = fopen("07a.c", "r")) == NULL || (arq2 = fopen("cripto.txt", "w")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	while(!feof(arq1)){
		c = getc(arq1);
		cripto(&c, &ok);
		putc(c, arq2);
	}
	fclose(arq1);
	fclose(arq2);
}
