#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void descripto(char * c, int * ok){
	if(* ok % 2 == 0)
		* c += -7;
	else
		* c += -3;
	ok++;
}

int main()
{
	FILE *arq1, *arq2;
	int i, tam, ok = 0;
	char c;
	
	if((arq1 = fopen("cripto.txt", "r")) == NULL || (arq2 = fopen("descripto.txt", "w")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	while(!feof(arq1)){
		c = getc(arq1);
		descripto(&c, &ok);
		putc(c, arq2);
	}
	fclose(arq1);
	fclose(arq2);
}
