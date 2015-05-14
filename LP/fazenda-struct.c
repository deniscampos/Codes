#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declarando estruturas de registros
struct data {
	int mes;
	int ano;
};

struct registro {
	char codigo[10];
	int leite;
	int alimento;
	char abate[1];
	struct data nascimento;
};

struct registro gado[2000];

int menu(){
	printf("\n------------------ MENU ------------------\n");
	printf("1 - Leite produzido/semana\n");
	printf("2 - Alimento consumido/semana\n");
	printf("3 - Leite produzido/semana após abate\n");
	printf("4 - Alimento consumido/semana após abate\n");
	printf("5 - Gados que irão para abate\n");
	printf("6 - Finalizar\n");
	printf("------------------------------------------\n");
}

void cadastrar(int * i){
	int newGado = 1;
	int k = * i;			//k recebe conteúdo para onde o i aponta
	while(newGado){
		printf("Código: ");
		scanf("%s", &gado[k].codigo);

		printf("Leite produzido: ");
		scanf("%d", &gado[k].leite);

		printf("Alimento consumido: ");
		scanf("%d", &gado[k].alimento);

		printf("Mes nascimento: ");
		scanf("%d", &gado[k].nascimento.mes);

		printf("Ano nascimento: ");
		scanf("%d", &gado[k].nascimento.ano);
		
        printf("------------------------------\n");
		printf("0 Finalizar  ou  1 Continuar\n");
		printf("------------------------------\n");
		scanf("%d", &newGado);
		* i = * i + 1; 		//acrescenta +1 no contador i, pois foi adicionado um gado
		k++;
	}
}

void abate(int * i) {
	double idade;
	int k, leite, alimento, anoHoje = 2015, mesHoje = 4;
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de gado cadastrados
		alimento = gado[k].alimento;
		leite = gado[k].leite;
		idade = (anoHoje - gado[k].nascimento.ano) + ((12 - gado[k].nascimento.mes + mesHoje) / 10.0);		
		if(gado[k].nascimento.mes >= mesHoje)
			idade--;

		if(idade > 5 || leite < 40 || (leite > 50 && leite < 70 && alimento > 50))
			gado[k].abate[0] = 'S';
		else
			gado[k].abate[0] = 'N';

		printf("%c\n", gado[k].abate[0]);
	}
}

void leite(int * i) {
	int k, totalLeite = 0;
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de gado cadastrados
		totalLeite += gado[k].leite;
	}
	printf("%d l de leite por semana.\n", totalLeite);
}

void leiteAbate(int * i) {
	int k, totalLeite = 0;
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de gado cadastrados
		if(gado[k].abate[0] == 'N')
			totalLeite += gado[k].leite;
	}
	printf("%d l de leite por semana após abate.\n", totalLeite);
}

void alimento(int * i) {
	int k, totalAlimento = 0;
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de gado cadastrados
		totalAlimento += gado[k].alimento;
	}
	printf("%d kg de alimento por semana.\n", totalAlimento);
}

void alimentoAbate(int * i) {
	int k, totalAlimento = 0;
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de gado cadastrados
		if(gado[k].abate[0] == 'N')
			totalAlimento += gado[k].alimento;
	}
	printf("%d kg de alimento por semana após abate.\n", totalAlimento);
}

void gadosAbate(int * i) {
	int k, totalAbate = 0;
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de gado cadastrados
		if(gado[k].abate[0] == 'S')
			totalAbate++;
	}
	printf("%d gados irão para abate.\n", totalAbate);
}

int main(){
	int i = 0;
	int menuUser = 0;
	cadastrar(&i);
	abate(&i);
	do {
		system("cls");
		menu();
		scanf("%d", &menuUser);

		switch(menuUser){
			case 1:
				leite(&i);  	//passa endereço de memória
				break;
			case 2:
				alimento(&i);
				break;
			case 3:
				leiteAbate(&i);
				break;
			case 4:
				alimentoAbate(&i);
				break;
			case 5:
				gadosAbate(&i);
				break;
			case 6:
				break;
			default:
				printf("Menu inválido\n");
				break;
		}
    	system("pause");
	} while(menuUser != 6);
}