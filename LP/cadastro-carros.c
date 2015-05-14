#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declarando tipo carro
struct carro{
	char marca[15];
	int ano;
	char cor[10];
	double preco;
};

struct carro vCars[20];

//menu
int menu(){
	printf("\n------------ MENU ------------\n");
	printf("1 - Cadastrar carro\n");
	printf("2 - Filtrar preço\n");
	printf("3 - Filtrar marca\n");
	printf("4 - Filtrar marca, ano e cor\n");
	printf("5 - Sair\n");
	printf("------------------------------\n");
}

//cadastro dos veículos
void cadastrar(int * i){
	int newCar = 1;
	int k = * i;			//k recebe conteúdo para onde o i aponta
	while(newCar){
		printf("Marca: ");
		scanf("%s", &vCars[k].marca);

		printf("Ano  : ");
		scanf("%d", &vCars[k].ano);

		printf("Cor  : ");
		scanf("%s", &vCars[k].cor);

		printf("Preço: ");
		scanf("%lf", &vCars[k].preco);
		
        printf("------------------------------\n");
		printf("0 Finalizar  ou  1 Continuar\n");
		printf("------------------------------\n");
		scanf("%d", &newCar);
		* i = * i + 1; 		//acrescenta +1 no contador i, pois foi adicionado um veículo
		k++;
	}
}

//Filtro por preço
void filtrarPreco(int * i){
	int k;
	double precoUser;
	printf("Digite o preço: ");
	scanf("%lf", &precoUser);
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de veículos cadastrados
		if(vCars[k].preco <= precoUser){
			printf("\n");
			printf("Marca: %s\n", vCars[k].marca);
			printf("Ano  : %d\n", vCars[k].ano);
			printf("Cor  : %s\n", vCars[k].cor);
		}
	}
	printf("\n");
}

//filtro por marca
void filtrarMarca(int * i){
	int k,  existe = 0;
	char marcaUser[15];
	printf("Digite a marca: ");
	scanf("%s", &marcaUser);
	for(k = 0; k < * i; k++){	//enquanto k menor que quant de veículos cadastrados
		if(!strcmp(vCars[k].marca, marcaUser)){
			existe = 1;
			printf("\n");
			printf("Preço: %.2lf\n", vCars[k].preco);
			printf("Ano  : %d\n", vCars[k].ano);
			printf("Cor  : %s\n", vCars[k].cor);
		}
	}
	if(!existe)
		printf("Nenhum carro encontrado.\n");
}

//filtro por marca, ano e cor
int filtrarMAC(int * i){
	int k,  existe = 0;
	char marcaUser[15], corUser[10];
	int anoUser;
	printf("Marca: ");
	scanf("%s", &marcaUser);
	printf("Ano  : ");
	scanf("%d", &anoUser);
	printf("Cor  : ");
	scanf("%s", &corUser);

	for(k = 0; k < * i; k++){	//enquanto k menor que quant de veículos cadastrados
		if(!strcmp(vCars[k].marca, marcaUser) && vCars[k].ano == anoUser && !strcmp(vCars[k].cor, corUser)){
			existe = 1;
			printf("Preço: %.2lf\n", vCars[k].preco);
		}
	}
	if(!existe)
		printf("Nenhum carro encontrado.\n");
}

int main(){
	int i = 0;
	int menuUser = 0;
	do {
		system("cls");
		menu();
		scanf("%d", &menuUser);

		switch(menuUser){
			case 1:
				cadastrar(&i);  	//passa endereço de memória
				break;
			case 2:
				filtrarPreco(&i);	//passa endereço de memória
				break;
			case 3:
				filtrarMarca(&i);	//passa endereço de memória
				break;
			case 4:
				filtrarMAC(&i);		//passa endereço de memória
				break;
			case 5:
				break;
			default:
				printf("Menu inválido\n");
				break;
		}
            system("pause");
	} while(menuUser != 5);
}