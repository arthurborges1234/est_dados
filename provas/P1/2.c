/*
Implemente um programa que possua uma função "remove_perfeitos". 
Essa função deve receber por parâmetro uma lista ligada e remover todos 
números perfeitos que estão dentro da lista. Na sua função principal leia 
do usuário N números e utilizando a 
função criada remova os números perfeito da lista de N números.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento *inicio;
}lista;

typedef struct elemento{
    int valor;
    struct elemento *proximo;
}elemento;


int encontra_perfeito(int numero);
void remove_perfeitos(lista *l);
void incluir_elemento(lista*l,int x);
lista *aloca_lista();
elemento *aloca_elemento();
void mostrar_lista(lista *l);


int main(){
    printf("quantos nuemros voce deseja adicionar a lista: ");
    int qtd;
    scanf("%d", &qtd);
    int *numeros;
    numeros = (int*)malloc(sizeof(int)*qtd);
    printf("informe %d numeros", qtd);
    
    lista *l = aloca_lista();
    for(int i = 0 ; i<qtd ; i++){
        scanf("%d", &numeros[i]);
        incluir_elemento(l,numeros[i]);

    }
    
    printf("lista antes de remover os numeros perfeitos:");
    mostrar_lista(l);

    remove_perfeitos(l);
    printf("lista depois de remover os numeros perfeitos:");
    
    mostrar_lista(l);

    return 0;
}

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

elemento *aloca_elemento(){
    elemento *novo;
    novo = (elemento *)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->proximo = NULL;
    return novo;
}

void mostrar_lista(lista *l){
        
    if(l->inicio==NULL){
        printf("\nLista vazia\n");
    }else{
        elemento *aux = l->inicio;

        while(aux != NULL){
            printf("%c ", aux->valor);
            aux = aux->proximo;
        }
    }

}

void incluir_elemento(lista*l, int x){
    
    elemento *novo = aloca_elemento();
    novo->valor = x;
    elemento *aux = l->inicio;
    while (aux->proximo!=NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
    
    l->qtd++;

}

int encontra_perfeito(int numero){

    int  soma = 0;

    for(int divisor= 1 ; (divisor<numero/2); divisor++){
        if(numero%divisor==0){
            soma+=divisor;
        }
    }
    if(soma==numero){
        return 1;
    }else{
        return 0;
    }
}


void remove_perfeitos(lista *l){
    if(l->inicio==NULL){
        printf("lista vazia");
    }else{
        elemento *aux , *ant;
        
        ant = l->inicio;
        aux = ant->proximo;
        while(aux!=NULL){
            if(l->qtd>1){
                if(encontra_perfeito(l->inicio->valor)==1){
                    l->inicio = aux->proximo;
                    
                    l->qtd--;
                    
                }else if(encontra_perfeito(aux->valor)==1){
                    
                    ant->proximo = aux->proximo;
                    ant = ant->proximo;
                    aux = aux->proximo;    
                    l->qtd--;

                }else{
                    ant = aux;
                    aux = aux->proximo;
                    
                }

            }else{
                l->inicio =NULL;
                l->qtd = 0;
            }
        }

    }
}