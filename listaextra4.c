/**
 * @file listaextra4.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * Faça uma função que receba um inteiro N como parâmetro. Calcule e retorne o resultado da seguinte série S:
 * n² + 1
 * ------
 * n  + 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void somatoria(int x){
    float S;
    for(int i = 0; i <= x; i++){
        S = S + ((pow(i, 2) + 1)/(i + 3));
    }
    printf("O resultado da somatoria e: %.2f", S);
}

int main(){
    int x;
    printf("Digite um numero ");
    scanf("%d", &x);

    somatoria(x);
}//main