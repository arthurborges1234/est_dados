#include<stdio.h>
#include <stdlib.h>

#define TAM 5
int pilha[TAM];
int topo=0;

void erro(){
    printf("favor selecionar uma das opcoe anteriormente indicadas\n");

}


void push(int x);
int empty();
int pop();
int stackpop();

int main(){
    printf("\n");
    int opcao;
    do{
        printf("\n 1 - push");
        printf("\n 2 - pop");
        printf("\n 3 - stackpop");
        printf("\n 4 - sair");


        switch (opcao)
        {
        case 1:
            int numero;
            scanf("%d", &numero);
            push(numero);

            break;
        case 2:
            numero = pop();
            printf("o numero que saiu foi: %d", numero);
            printf("%d itens estao presentes na plha", topo);

            break;


        case 3:
            numero = stackpop();
            printf("o ultimo numero da lista é: %d", numero);

            break;
        default:
            erro();
            break;
        }



    }while (opcao!=5);
    


    return 0;
}

int empty(){
    if(topo == 0 ){
        return 1;
    }else{
        return 0;
    }
}

void push(int x){
    if (topo == TAM){
        printf("pilha cheia");
    }else{
        pilha[topo]=x;
        topo ++;
    }
}


int pop(){
    if(empty()){
        printf("pilha vazia\n");
    }else{
        return pilha[--topo];
    }
}


int stackpop(){
    if(empty()){
        printf("pilha vazia\n");
    }else{
        return pilha[topo-1];
    }
}