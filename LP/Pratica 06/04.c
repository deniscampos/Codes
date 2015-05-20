#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *p;
	char texto[300];
	int i, linha = 0, fim = 0;
	if((p = fopen("texto.txt", "w")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	printf("Digite seu texto\n");
	while(fim == 0 && linha < 50) {
		gets(texto);
		if(texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M' && texto[3] == '\0'){
			fim = 1;
		} else {
			for(i = 0; texto[i]; i++)
				putc(texto[i], p);
			putc('\n', p);
			linha++;
		}
	}
	fclose(p);
}
