#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro{
    float um,dois;
    int um1,dois2;

}registro;

int main(){

    printf("O tamanho de um inteiro e de: %ld bytes\n",sizeof(int));
    printf("O tamanho de um char e de: %ld bytes\n",sizeof(char));
    printf("O tamanho de um float e de: %ld bytes\n",sizeof(float));
    printf("O tamanho de um registro e de: %ld bytes\n",sizeof(registro));


    int x = 2 ;
    

    int *ptr;

    ptr=&x;

    printf("\nConteudo de x: %d", x);
    printf("\nConteudo de ptr: %d",ptr);
    printf("\n Endereco de x: %d",&x);
    printf("\n Endereco de ptr: %d",&ptr);
    printf("\nConteudo apontado por ptr: %d\n", *ptr);

    

    int *y,*z

    y = malloc(4)
    

    

    //    cast=(* tipo)  
    z= (*int)malloc(sizeof(int));
    
    free(z);




    


    return 0;
}