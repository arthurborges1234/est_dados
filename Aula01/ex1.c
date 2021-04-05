#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#define limpa() system("clear")



typedef struct sanduiche{
    char nome[20];
    float valor, peso;
    int avaliacao;
}sanduiche;

void mostra_sanduiche(sanduiche menu);
void recebe_sanduiches(sanduiche *menu, int qtd);
void lista(sanduiche *menu, int qtd);
int melhor_avaliado(sanduiche *menu, int qtd);
void peso_medio(sanduiche *menu, int qtd);
void compra(sanduiche *menu, int qtd);

int main(){

    setlocale(LC_ALL,"Portuguese");

    sanduiche *menu;

    int qtd_sanduiches;
    printf("Informe quantos sanduiches tem no cardápio:");
    scanf("%d", &qtd_sanduiches);

    menu = (sanduiche*)malloc(sizeof(sanduiche)*qtd_sanduiches);

    recebe_sanduiches(menu,qtd_sanduiches);

    int opcao;
    opcao=1;
    limpa();

    while (opcao!=0)
    {
        
        printf("digite:\n");
        printf("1-para listar sanduiches cujo nome se inicia com a letra A\n");
        printf("2-para mostrar o sanduiche mais bem avaliado\n");
        printf("3-para calcular o peso médio dos sanduiches\n");
        printf("4-para calcular compra de 3 produtos de cada\n");
        printf("0-para sair\n");

        scanf("%d", &opcao);
        
        switch (opcao){
        case 1:
            limpa();
            lista(menu, qtd_sanduiches);
        
            break;

        case 2:
            limpa();
            int aux = melhor_avaliado(menu , qtd_sanduiches);
            for(int i = 0; i<qtd_sanduiches; i++){
                
                if(aux == menu[i].avaliacao){
                    
                    mostra_sanduiche(menu[i]);

                }

            }

            break;
        case 3:
            limpa();

            peso_medio(menu, qtd_sanduiches);
            break;

        case 4:
            limpa();

            compra(menu,qtd_sanduiches);
            break;

        case 0:
            limpa();

            printf("Até logo\n");
            sleep(1);
            limpa();
            break;

        default:
            limpa();

            printf("Favor escolher uma das opções indicadas\n");
            break;

        }

    }

    return EXIT_SUCCESS;
}

void recebe_sanduiches(sanduiche *menu, int qtd){



    for(int i =0 ;i<qtd ;i++){
        printf("Sanduiche %d\n\n",i+1);

        printf("informe: \n");
        printf("nome do sanduiche:");
        setbuf(stdin,NULL);
        fgets(menu[i].nome,20,stdin);

        printf("preço do sanduiche:");        
        scanf("%f", &menu[i].valor);
        
        printf("peso do sanduiche:");
        scanf("%f", &menu[i].peso);

        printf("avaliação do sanduiche:");
        scanf("%d", &menu[i].avaliacao);

    }
    
}

void mostra_sanduiche(sanduiche menu){

    printf("\nNome: %s", menu.nome);
    printf("Preço: %.2f\n", menu.valor);
    printf("Peso: %.2f\n", menu.peso);
    printf("Avaliação: %d\n\n", menu.avaliacao);

}

void lista(sanduiche *menu, int qtd){
    for(int i =0 ; i <qtd; i++){
        if (menu[i].nome[0]=='A' ||menu[i].nome[0]=='a'){
            
            mostra_sanduiche(menu[i]);

        }
        

    }


}

int melhor_avaliado(sanduiche *menu, int qtd){
    int avaliacao=0;

    for(int i =0 ; i<qtd; i++){
        if(menu[i].avaliacao>avaliacao){
            
            avaliacao = menu[i].avaliacao;

        }

    }

    return avaliacao;

}

void peso_medio(sanduiche *menu, int qtd){

    
    float aux;

    aux=0;

    for(int i = 0 ; i <qtd ; i++){
        aux+=menu[i].peso;
    }
    aux = aux/qtd;
    printf("Peso médio: %.2f\n", aux);
}

void compra(sanduiche *menu, int qtd){
    
    float conta=0;

    for(int i = 0 ; i<qtd; i++){

        conta+= (menu[i].valor*3);

    }

    printf("Conta: %.2f\n", conta);


}