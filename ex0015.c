/**
 * @file ex0015.c
 * @author dimitri maia
 * @brief 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * Crie uma função que retorne x elevado a y através de operação de
multiplicação. A função recebe x e y por parâmetro
 */

#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y){
    int cal;
    if (x == 0 || y == 0) return 1;
    else cal = x * potencia(x, y - 1);
    return cal;
}//função

int main(){
    int x, y;
    printf("\nDigite um valor para x: ");
    scanf("%d", &x);
    printf("\nDigite um valor para y: ");
    scanf("%d", &y);
    
    //chamada de função
    potencia(x, y);
    printf("\nResultado da potencia: %d\n", potencia(x, y));
    return 0;
}

