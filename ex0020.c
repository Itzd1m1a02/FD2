/**
 * @file ex0020.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * Crie um programa que contenha uma matriz (3x3) de float. Imprima o
endereço de cada posição dessa matriz.
 */

#include <stdio.h>
#include <stdlib.h>
void enderecos(int x[][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("O valor do endereco de memoria e[%d][%d]: %p\n", i+1, j+1, &x[i][j]);
        }//for
    }//for
}//função

int main(){
    float x[3][3];
    enderecos(x);
}//main
