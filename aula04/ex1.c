/* 
    1) Construa uma estrutura de lista duplamente ligada que permita as seguintes operações:
    a) Incluir no inicio da lista
    b) incluir no final da lista
    c) mostrar lista
    d) mostrar primos da lista
    e) mostrar lista de tras pra frente
    f) remover elemento da lista
    g) remover primos da lista

*/



#include <stdio.h>
#include <stdlib.h>

#define limpa() system("clear")
#define false 1
#define true 0



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
void incluir_no_inicio(lista *l, int x);
void incluir_no_final(lista *l, int x);
int encontra_primos(int x);
int esta_na_lista(lista *l,int x);
void mostra_primos(lista *l);
void remove_elemento(lista *l,int x);
void mostrar_lista(lista *l);
void mostrar_lista_contrario(lista *l);
void remove_primos(lista *l);
void erro(){
    printf("opcao indisoponivel\n");
    printf("favor escolher uma das opcoes indicadas\n\n");
}
void menu(){
    printf("Digite:\n");
    printf("1 - Incluir no inicio da lista\n");
    printf("2 - Incluir no final da lista\n");
    printf("3 - mostrar lista\n");
    printf("4 - mostrar primos da lista\n");
    printf("5 - mostrar lista de tras pra frente\n");
    printf("6 - remover elemento da lista\n");
    printf("7 - remover primos da lista\n");
    printf("0 - sair\n");
}

int main(){

    lista *l1;
    int opcao= 1;
    l1=aloca_lista();
    while (opcao!=0){
        
        menu();
        
        scanf("%d", &opcao);
        int numero;
        switch (opcao){

            case 0:
                limpa();
                printf("Ate logo\n");
                
                break;
            case 1:
                limpa();

                printf("insira um numero: ");
                
                scanf("%d", &numero);
                incluir_no_inicio(l1,numero);


                break;
            
            case 2:
                limpa();
                
                printf("insira um numero: ");
                scanf("%d", &numero);
                incluir_no_final(l1,numero);

                break;

            case 3:
                limpa();

                mostrar_lista(l1);

                break;

            case 4:
                limpa();

                mostra_primos(l1);

                break;
            case 5:
                limpa();

                mostrar_lista_contrario(l1);

                break;

            case 6:
                limpa();
                
                printf("informe o numero que voce deseja remover:");
                scanf("%d",&numero);
                remove_elemento(l1,numero);


                break;

            case 7:
                limpa();

                remove_primos(l1);

                break;

            default:
                limpa();
                erro();

                break;
            }

    }
    
    
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

void incluir_no_inicio(lista *l, int x){
    registro *novo = aloca_registro(x);

    if(l->inicio==NULL){
        l->inicio=novo;
        l->fim=novo;
    }else{
        l->inicio->ant=novo;
        novo->prox=l->inicio;
        l->inicio=novo;

    }

    l->qtd++;
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

int encontra_primos(int x){
    if(x<=1){
        return false;
    }else{
        for(int i = 2; i<=(x/2); i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    
}

void mostra_primos(lista *l){
    if(l->inicio==NULL){
        printf("Lista vazia\n\n");
    }else{
        registro *aux;
        int qtd_primos = 0;
        aux = l->inicio;
        while(aux!=NULL){
            int bol=encontra_primos(aux->valor);
            
            if(bol==true){
                printf("->%d", aux->valor);
                qtd_primos++;
            }
            aux = aux->prox;
        }

        if(!qtd_primos)
            printf("Nao existem numeros primos na sua lista\n\n");




        printf("\n");
    }
}

void mostrar_lista_contrario(lista *l){
    if(l->inicio == NULL){
        printf("Lista vazia\n\n");
    }else{
        registro *aux = l->fim;
        
        while(aux){
            printf("%d<-",aux->valor);
            aux = aux->ant;
        }
        printf("\n\n");

    }

}

void remove_elemento(lista *l,int x){
    

    if(l->inicio==NULL){
        printf("Lista vazia\n\n");
    }else{
        int confere = esta_na_lista(l,x);
        if(confere==true){
            registro *atual = l->inicio;
            while(atual!=NULL){
                    
                if(atual->valor == x){
                    if(l->qtd==1){
                        
                        l->fim=NULL;
                        l->inicio=NULL;
                    }else{

                        if(l->inicio->valor==x){

                            l->inicio = l->inicio->prox;
                            l->inicio->ant=NULL;

                        }else if(l->fim->valor == x){
                        
                            l->fim = l->fim->ant;
                            l->fim->prox=NULL;
                        
                        }else{

                            registro *aux = atual->ant;
                            aux->prox = atual->prox;
                            atual->prox->ant=aux;

                        }  

                    }
                    
                }
                atual = atual->prox;
                l->qtd--;
            }

        }else{

            printf("O elemento que voce deseja remover nao esta presente na lista");

        }
    }

}

void remove_primos(lista *l){
    if(l->inicio==NULL){
        printf("Lista vazia\n\n");
    }else{
        registro *aux;
        aux = l->inicio;
        int qtd_primos=0;
        while(aux!=NULL){
            int bol=encontra_primos(aux->valor);
            
            if(bol==true){

                remove_elemento(l,aux->valor);
                qtd_primos+=1;
            }
            aux = aux->prox;
        }
        if(!qtd_primos)
            printf("Nao existem numeros primos na sua lista\n");

        
        
        printf("\n");
    }
}

int esta_na_lista(lista *l ,int x){
    int cont=0;

    registro *aux;

    aux = l->inicio;
    while(aux!=NULL){
        if(aux->valor==x){
            cont+=1;
        }
    }
    
    if(cont>0){
        return true;
    }else{
        return false;
    }
}
