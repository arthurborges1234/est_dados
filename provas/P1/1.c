/*
Implemente uma lista ligada de caracteres em C, ou seja, cada registro da lista
deve possui apenas 1 caractere. Construa uma função chamada
"separa_vogais_consoantes". Essa função irá receber 3 listas (lista_a, lista_b,
lista_c) e deverá incluir na lista_b todas as vogais contidas na lista_a e incluir na
lista_c todas as consoantes contidas na lista_a. Na sua função principal, solicite
um texto ao usuário e mostre a lista de vogais e consoantes utilizando a função criada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
    int qtd;
    struct car *inicio;
}lista;

typedef struct car
{
    char letra;
    struct car *proximo;
}car;

void incluir_elemento(lista *l,char letra);
void mostrar_lista(lista *l);
lista *aloca_lista();
car *aloca_car(char letra);
void separa_vogais_consoantes(lista *l_a,lista *l_b ,lista *l_c);


int main(){
    lista *l_a, *l_b , *l_c;

    l_a = aloca_lista();
    l_b = aloca_lista();
    l_c = aloca_lista();

    printf("digite umas frase:");
    char *frase;
    frase = (char*)malloc(sizeof(char)*50);

    setbuf(stdin,NULL);
    fgets(frase , 50 ,stdin);

    for(int i = 0; i < strlen(frase)-1; i++){
        incluir_elemento(l_a,frase[i]);
    }
    system("clear");
    printf("sua frase:%s",frase);
    separa_vogais_consoantes(l_a,l_b,l_c);
    printf("lista de vogais:");
    mostrar_lista(l_b);
    printf("\nlista de consoantes:");
    mostrar_lista(l_c);
    
    
    printf("\n\n");
    return 0;
}
lista *aloca_lista(){
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio = NULL;
    return novo;
}
car *aloca_car(char letra)
{
    car *novo;
    novo = (car *)malloc(sizeof(car));
    novo->letra = letra;
    novo->proximo = NULL;
    return novo;
}
void incluir_elemento(lista *l,char letra){
    car *novo = aloca_car(letra);
    car *aux = aloca_car(0);
    if(l->inicio==NULL){
        l->inicio = novo;
    }else{
        aux = l->inicio;
        while (aux->proximo!=NULL){
            aux = aux->proximo;

        }
        aux->proximo = novo;
    }
    l->qtd++;
}
void mostrar_lista(lista *l){
        
    if(l->inicio==NULL){
        printf("\nLista vazia\n");
    }else{
        car *aux = l->inicio;

        while(aux != NULL){
            printf("%c ", aux->letra);
            aux = aux->proximo;
        }
    }

}
void separa_vogais_consoantes(lista *l_a,lista *l_b ,lista *l_c){
    if(l_a->inicio == NULL){
        printf("\nlista A esta vazia\n");
    }else{
        car *aux= aloca_car(0);
        aux = l_a->inicio;
        int anda = 0 ;
        while(aux!=NULL){
            if(aux->letra=='a'||aux->letra=='e'||aux->letra=='i'||aux->letra=='o'||aux->letra=='u'){
                incluir_elemento(l_b , aux->letra);
            }else{
                incluir_elemento(l_c, aux->letra);
            }
            aux = aux->proximo;
        }
    }
}