#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE *p;

struct endereco{
	char rua[90];
	int numero;
	char complemento[20];
	char bairro[90];
	int cep;
	char cidade[50];
	char estado[50];
	char pais[50];
};

struct telefone{
	int ddd;
	int fone;
};

struct aniversario{
	int dia;
	int mes;
	int ano;
};

struct dadosCadastro{
	char nome[50];
	char email[50];
	struct endereco end;
	struct telefone tel;
	struct aniversario dtAn;
	char obs[150];
};

struct dadosCadastro agenda[10];

int busca_nome(){
	char nome[50], nomeP[50];
	int i;

	if((p = fopen("agenda.txt", "r")) == NULL){
		printf("Erro ao abrir arquivo!");
		exit(1);
	}	

	gets(nome);

	while(!feof(p)){

		if (fgets(nomeP, 50, p) == nome)
		{
			printf("%s\n", nomeP);
			
		}
	}
}


int main(){

	int n, i;

	i = 0;

	if((p = fopen("agenda.txt", "w+")) == NULL){
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	do
	{
		printf("Escolha uma opção\n\n");
		printf("Cadastrar______(1)\nProcurar_______(2)\nSair___________(3)\n");
		scanf("%d", &n);

		if (n == 1)
		{
			fflush(stdin);

			printf("\t_____Cadastrar_____\nNome: ");
			gets(agenda[i].nome);
			fprintf(p, "%s\n", agenda[i].nome);
			fflush(stdin);

			printf("E-mail: ");
			gets(agenda[i].email);
			fprintf(p, "%s\n", agenda[i].email);
			fflush(stdin);

			printf("\n_____Endereco_____\nRua: ");
			gets(agenda[i].end.rua);
			fprintf(p, "%s\n", agenda[i].end.rua);
			fflush(stdin);

			printf("Numero: ");
			scanf("%d", &agenda[i].end.numero);
			fprintf(p, "%d\n", agenda[i].end.numero);
			fflush(stdin);

			printf("Complemento: ");
			gets(agenda[i].end.complemento);
			fprintf(p, "%s\n", agenda[i].end.complemento);
			fflush(stdin);

			printf("Bairro: ");
			gets(agenda[i].end.bairro);
			fprintf(p, "%s\n", agenda[i].end.bairro);
			fflush(stdin);

			printf("CEP(apenas numeros): ");
			scanf("%d", &agenda[i].end.cep);
			fprintf(p, "%d\n", agenda[i].end.cep);
			fflush(stdin);

			printf("Cidade: ");
			gets(agenda[i].end.cidade);
			fprintf(p, "%s\n", agenda[i].end.cidade);
			fflush(stdin);

			printf("Estado: ");
			gets(agenda[i].end.estado);
			fprintf(p, "%s\n", agenda[i].end.estado);
			fflush(stdin);

			printf("Pais: ");
			gets(agenda[i].end.pais);
			fprintf(p, "%s\n", agenda[i].end.pais);
			fflush(stdin);

			printf("\n_____Data de Nascimento_____\nDia: ");
			scanf("%d", &agenda[i].dtAn.dia);
			fprintf(p, "%d\n", agenda[i].dtAn.dia);
			fflush(stdin);

			printf("Mes: ");
			scanf("%d", &agenda[i].dtAn.mes);
			fprintf(p, "%d\n", agenda[i].dtAn.mes);
			fflush(stdin);

			printf("Ano: ");
			scanf("%d", &agenda[i].dtAn.ano);
			fprintf(p, "%d\n", agenda[i].dtAn.ano);

			printf("\n\n*** Cadastro concluido ***\n\n");
			i++;
		}
		if (n>3){
			printf("Opção inválida!\n");
		}

		if (n == 2)
		{
			fclose(p);
			busca_nome();
		}

	}while(n != 3);


fclose(p);
getch();
}

/*
11.  Fazer um programa para simular uma agenda de telefones. Para cada pessoa deve-se ter os seguintes dados:
• Nome
• E-mail
• Endereço (contendo campos para Rua, numero, complemento, bairro, cep, cidade, estado, país)
• Telefone (contendo campo para DDD e número)
• Data de aniversário (contendo campo para dia, mês, ano)
• Observações : Uma linha (string) para alguma observações especial.
a)	Definir a estrutura acima.
b)	Declarar a variável agenda (vetor) com capacidade de agendar até 10 nomes.
c)	Gravar os dados desse vetor em um arquivo chamado agenda.txt.
d)	Definir um função para buscar por primeiro nome(busca_nome) no arquivo agenda.txt: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas)
*/
