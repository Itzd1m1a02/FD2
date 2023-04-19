/**
 * @file ex0019.c
 * @author dimitri maia (dimitrimaia@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * Crie um programa que contenha um vetor float (tamanho 10). Imprima o
endereço de cada posição desse vetor.
 */

#include <stdio.h>
#include <stdlib.h>

void enderecos(int x[]){
    for (int i = 0; i < 10; i++){
        printf("O valor do endereco de memoria e[%d]: %p\n",i+1, &x[i]);
    }//for
}//funcao

int main(){
    float x[10];
    enderecos(x);
}//main