/**
 * @file ex0021.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 * Crie um programa que contenha um vetor de inteiros de tamanho 5.
Utilizando aritmética de ponteiros, leia os dados do teclado e exiba seus
valores multiplicado por 2. Em seguida, exiba o endereço de memória das
posições que contém valores pares.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x[5];
    int cal[5];

    for (int i = 0; i < 5; i++){
        printf("\nDigite o valor[%d]: ", i+1);
        scanf("%d", &x[i]);
    }//for

    for (int i = 0; i < 5; i++){
        cal[i] = x[i] * 2;
        printf("\no dobro do valor e [%d]: %d\n", i+1, cal[i]);
    }//for

    for (int i = 0; i < 5; i++){
        if(cal[i] % 2 != 0) printf("O endereco de memoria na posicao[%d] e par: %p\n", i+1, &cal[i]);
    }//for
}//main
