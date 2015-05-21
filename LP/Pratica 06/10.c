#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arq1;
	int i;
	char c, nome[50];
	
	printf("Escreva o nome do arquivo de TEXTO que deseja ler.\nDEVE conter a extensão do arquivo e o mesmo DEVE estar na mesma pasta desse programa.\nNome arquivo: ");
	gets(nome);
	//fgets(nome, sizeof(nome), stdin); //NAO FUNCIONOU COM FGETS

	if((arq1 = fopen(nome, "r")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	while(!feof(arq1)){
		c = getc(arq1);
		//printf("%c", c); //APENAS TESTE DE LEITURA
	}
	fclose(arq1);
}
