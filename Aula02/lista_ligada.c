#include <stdio.h>
#include <stdlib.h>
#include <string.h>
            
#define limpa() system("clear")

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);

void mostrar_lista(lista *l);
void mostrar_pares_lista(lista *l);

int main(){

    lista *l1;
    int x = 0;

    l1 = aloca_lista();

    int opcao=1;


    while(opcao!=0){
        printf("Digite:\n");
        printf("1-Adicionar item a lista\n");
        printf("2-Mostrar lista\n");
        printf("3-Mostrar apenas pares da lista\n");
        printf("0-Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            limpa();

            printf("\n Qual numero deseja inserir?\n");
            scanf("%d", &x);
            incluir_no_final(l1, x);
            break;
        
        case 2:
            limpa();

            mostrar_lista(l1);

            break;

        case 3:
            limpa();

            mostrar_pares_lista(l1);
            break;
        case 0:

            limpa();
            printf("Ate breve\n");

            break;
        default:
            limpa();

            printf("opcao indisponivel\n");
            break;
        }


    }



    /*while (x != -1)
    {
        printf("\n Qual numero deseja inserir?");
        scanf("%d", &x);
        if (x != -1)
        {
            incluir_no_final(l1, x);
        }
    }*/

    //mostrar_lista(l1);

    printf("\n");



    return 0;
}


lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\nValor = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

void mostrar_pares_lista(lista *l){
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            if(aux->valor%2==0){
                printf("\nValor = %d\n", aux->valor);
                aux = aux->prox;


            }
            
        }
    }
}
