#include <stdio.h>
#include <string.h>

void ordAlfabetica(char * word, char * ordem){
    int menor, x, i, n = 0;
    int tamanho = strlen(word);
    int original = strlen(word);

    while(tamanho){
        for(x = 0; word[x] != '\0'; x++){ //Analisa caracter por caracter da palavra
            for(i = 0; word[i] != '\0'; i++){
                if(word[x] > word[i]){
                    menor = 0; //Não é o menor caracter
                    break; //Para e passa a verificar o próximo
                } else {
                    menor = 1; //Diz que o caracter é menor que os outros que foram comparados
                }
            }
            if(menor && n < original){ //verifica se o caracter é o menor e se o tamanho da nova palavra é menor que a original
                ordem[n] = word[x]; //ordem recebe o menor caracter encontrado
                n++; //incrimenta para adicionar o próximo caracter na próxima posição
                for(i = 0; i < tamanho; i++)
                    if(i < x)
                        word[i] = word[i]; //copia a primeira parte da palavra
                    else
                        word[i] = word[i + 1]; //exclui o menor caracter e copia o resto
                word[i-1] = '\0'; //define o final da string
                tamanho--; //reduz tamanho pois um caracter foi removido
            }
        }
    }
}

int main() {
    int x, anagrama;
    char a[50],b[50];

    printf("Digite a primeira palavra\n");
    gets(a);
    printf("Digite a segunda palavra\n");
    gets(b);
    char origA[strlen(a)], origB[strlen(b)]; //variáveis para guardar a palavra original que será modificada
    for(x = 0; a[x] != '\0'; x++) //guarda a primeira palavra
        origA[x] = a[x];
    origA[x] = '\0';
    for(x = 0; b[x] != '\0'; x++) //guarda a segunda palavra
        origB[x] = b[x];
    origB[x] = '\0';

    char ordA[strlen(a)], ordB[strlen(b)]; //variáveis onde serão retornadas a palavra em ordem alfabética

    ordAlfabetica(a, ordA); //passa a palavra e retorna ela em ordem alfabética em ordA
    ordAlfabetica(b, ordB); //passa a palavra e retorna ela em ordem alfabética em ordA
   
    //abaixo comparação dos retornos

    if(strlen(a) != strlen(b)) //se não tem o mesmo tamanho, não são anagramas
        printf("\n%s nao eh anagrama de %s.", origA, origB);
    else {
        for(x = 0; ordA[x] != '\0'; x++){
            if (ordA[x] != ordB[x]){ //compara posição com posição da palavra em ordem alfabética
                anagrama = 0; // se entrar no if não é anagrama, pois há caracteres diferentes
                printf("\n%s nao eh anagrama de %s.\n", origA, origB);
                break;
            }
        }
        if(anagrama)
            printf("\n%s eh anagrama de %s.\n", origA, origB);
    }
}
