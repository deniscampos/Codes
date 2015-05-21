#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arq1, *arq2;
	int i;
	char c, stop = 0;
	
	if((arq1 = fopen("09.html", "r")) == NULL || (arq2 = fopen("09-texto.txt", "w")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	while(!feof(arq1)){
		c = getc(arq1);
		if(stop == 0 && c == '<'){
			stop = 1;
		} else if(stop == 1 && c == '>'){
			stop = 0;
		}
		if(!stop && c != '<' && c != '>'){
			putc(c, arq2);
		}
	}
	fclose(arq1);
	fclose(arq2);
}
