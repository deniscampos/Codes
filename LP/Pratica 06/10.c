#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void listar(char texto[100][100]) {
	int inicio, fim, i, x;
	printf("Linha inicial: ");
	scanf("%d", &inicio);
	printf("Final: ");
	scanf("%d", &fim);

	for(i = inicio; i <= fim; i++){
		for(x = 0; texto[i][x] != '\0'; x++){
			printf("%c", texto[i][x]);
		}
	}
}
void editar(char texto[100][100]) {}
void inserir(char texto[100][100]) {}
void apagar(char texto[100][100]) {}
void abandonar(char texto[100][100]) {}
void sairSalvar(char texto[100][100]) {}

int menu(){
	int menuUser;
	printf("\n");
	printf("1 - Listar\n");
	printf("2 - Editar\n");
	printf("3 - Inserir\n");
	printf("4 - Apagar\n");
	printf("5 - Abandonar\n");
	printf("6 - Sair e salvar\n");
	printf("Escolha o que deseja fazer: ");

	scanf("%d", &menuUser);

	return(menuUser);
}

int main()
{
	FILE *arquivo;
	int i, x, m;
	char c, nome[100], linha[100], texto[1000][100];
	
	printf("Escreva o nome do arquivo de TEXTO que deseja ler.\nDEVE conter a extensão do arquivo e o mesmo DEVE estar na mesma pasta desse programa.\nNome arquivo: ");
	gets(nome);

	if((arquivo = fopen(nome, "r")) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
	for(i = 0; !feof(arquivo); i++) {
		fgets(linha, 100, arquivo);
		printf("%d -> ", i);

		for(x = 0; linha[x] != '\0'; x++){
			texto[i][x] = linha[x];
			printf("%c", texto[i][x]);
		}
	}
	printf("\n");

	while(m != 5 && m != 6){
		m = menu();
		switch(m){
			case 1:
				listar(texto);
				break;
			case 2:
				editar(texto);
				break;
			case 3:
				inserir(texto);
				break;
			case 4:
				apagar(texto);
				break;
			case 5:
				abandonar(texto);
				break;
			case 6:
				sairSalvar(texto);
				break;
			default:
				printf("Menu inválido\n");
				break;
		}
	}

	fclose(arquivo);
}

/*Faça um editor de textos, inspirado no NotePad (Bloco de Notas) ou
WordPad/Word, que permita ao usuário inicialmente ler um texto de um arquivo
texto armazenado em disco, armazene este texto em um vetor de strings em
memória, onde cada linha do texto terá um número indicando a linha
correspondente. Uma vez lido o arquivo, o programa deve ler comandos do
usuário (laço), que poderá ser um dos seguintes comandos: 

Listar (opção 1: indicar o intervalo de linhas que deseja exibir na tela, 
linha inicial até linha final); 

Editar (opção 2: indicar qual a linha deseja editar, mostrar o
seu conteúdo atual, ler um novo conteúdo e substituir o conteúdo da linha
antiga pelo novo conteúdo); 

Inserir (opção 3: indicar depois de qual linha desejo inserir uma nova 
linha de texto, “abrindo espaço”  após esta linha e inserindo um novo texto);

Apagar (opção 4: indicar qual linha deseja apagar, exibir seu conteúdo, 
confirmar a remoção e remover esta linha do texto);

Abandonar (opção 5: sair do programa, sem salvar o texto editado, onde é
pedida uma confirmação do usuário sobre a execução desta opção); 

Sair (opção 6: sair do programa, onde o texto será salvo em um arquivo em 
disco sobrescrevendo o arquivo original, sendo pedida uma confirmação 
do usuário sobre a execução desta opção). 

O programa no final deve portanto ter a capacidade de ler um arquivo de 
texto do disco, editar (listar, incluir, excluir, modificar linhas de texto) 
salvar em disco o texto novo que foi editado, executando as operações 
usuais de um editor de textos simples.
*/