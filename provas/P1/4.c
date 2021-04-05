#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
    
}lista;

typedef struct registro{

    int valor;
    struct registro *ant;
    struct registro *prox;
    
}registro;

lista *aloca_lista();
registro *aloca_registro(int valor);
void incluir_no_final(lista *l, int x);
void inverter_listas(lista *l1 , lista *l2);
void mostrar_lista(lista *l);


int main(){
    lista *l1, *l2;
    
    l1=aloca_lista();
    l2=aloca_lista();

    printf("quantos numeros voce deseja adicionar na lista 1?\n");
    int n;
    scanf("%d",&n);
    int *num1 = (int*)malloc(sizeof(int)*n);
    
    
     
    printf("quantos numeros voce deseja adicionar na lista 2?\n");
    int m;
    scanf("%d",&m);
    int *num2 = (int*)malloc(sizeof(int)*m);
    
    
    
    printf("insira os numeros da lista 1: ");
    for(int i = 0 ;i <n; i++){
        scanf("%d", &num1[i]);
        incluir_no_final(l1,num1[i]);
        
    }
    printf("insira os numeros da lista 2: ");
    for(int i = 0 ;i <m; i++){
        scanf("%d", &num2[i]);

        incluir_no_final(l2,num2[i]);
        
    }
    
    printf("Listas antes do processamento:\n");

    printf("Lista 1: ");
    mostrar_lista(l1);

    printf("Lista 2: ");
    mostrar_lista(l2);

    printf("Listas depois do processamento:\n");
    inverter_listas(l1,l2);
    
    printf("Lista 1: ");
    mostrar_lista(l1);
    
    printf("Lista 2: ");
    mostrar_lista(l2);


    return 0;
}

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)calloc(1,sizeof(lista));
    
    return novo;
}

registro *aloca_registro(int valor){

    registro *novo;
    novo = (registro *)calloc(1,sizeof(registro));
    novo->valor=valor;
    
    return novo;
}

void incluir_no_final(lista *l, int x){
    registro *novo = aloca_registro(x);

    if(l->fim==NULL){
        l->inicio=novo;
        l->fim=novo;
    }else{
        novo->ant=l->fim;
        l->fim->prox=novo;
        l->fim =novo;
    }
    l->qtd++;
}

void inverter_listas(lista *l1 , lista *l2){
    lista *auxiliar1 , *auxiliar2;
    auxiliar1 = aloca_lista();
    auxiliar2 = aloca_lista();


    if(l1->inicio == NULL){
        printf("Lista 1 vazia\n\n");
    }else{
        registro *aux = l1->fim;
        
        while(aux){
            incluir_no_final(auxiliar1, aux->valor);
            aux = aux->ant;
        }

    }

    if(l2->inicio == NULL){
        printf("Lista 2 vazia\n\n");
    }else{
        registro *aux = l2->fim;
        
        while(aux){
            incluir_no_final(auxiliar2, aux->valor);
            aux = aux->ant;
        }
            
        

    }


    l1->inicio= auxiliar2->inicio;
    l1->fim = auxiliar2->fim;
    l1->qtd = auxiliar2->qtd;
    l2->inicio= auxiliar1->inicio;
    l2->qtd = auxiliar1->qtd;
    l2->fim = auxiliar1->fim;

    
    free(auxiliar1);
    free(auxiliar2);


}

void mostrar_lista(lista *l){
    if(l->inicio==NULL){
        printf("Lista vazia\n");
    }else{
        registro *aux;

        aux = l->inicio;
        while(aux!=NULL){
            printf("->%d", aux->valor);
            aux = aux->prox;
        }
        printf("\n\n");
    }
}