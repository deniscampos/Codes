#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *p;
	char nome[100];
	int i, cont = 0, fim = 0;
	double n1, n2, media;
	if((p = fopen("05-Notas.txt", "w")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	
	while(cont < 10) {
		printf("Nome do aluno: ");
		fgets(nome, sizeof(nome), stdin);
		for(i = 0; nome[i]; i++)
			putc(nome[i], p);

		printf("Nota 1: ");
		scanf("%lf%*c", &n1);
		fprintf(p, "%.2lf\n", n1);

		printf("Nota 2: ");
		scanf("%lf%*c", &n2);
		fprintf(p, "%.2lf\n", n2);

		media = (n1 + n2) / 2;
		fprintf(p, "%.2lf\n", media);
		
		putc('\n', p);
		cont++;
	}
	fclose(p);
}
