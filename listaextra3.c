/**
 * @file listaextra2.c
 * @author dimitri (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-12
 * 
 * @copyright Copyright (c) 2023
 * Elabore uma função que receba como parâmetro um valor inteiro n e gere como saída um triângulo lateral formado por asteriscos conforme o exemplo a seguir, em que usamos n = 4:
*
**
***
****
***
**
*
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void triangulo(int x){
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= i; j++){
            printf("*");
        }//for
        printf("\n");
    }//for
    for (int i = x - 1; i >= 1; i--){
        for (int j = i; j >= 1; j--){
            printf("*");
        }//for
        printf("\n");
    }//for
}//função

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    triangulo(num);
}//main
