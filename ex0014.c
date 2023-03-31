/**
 * @file ex0014.c
 * @author dimitri maia
 * @brief 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 * Crie uma função que retorne x*y através de operação de soma. A função
   recebe x e y por parâmetro
 */

#include <stdio.h>
#include <stdlib.h>

int multiplica(int x, int y){
    int cal;
    if (x == 0 || y == 0) return 0;
    else cal = x + multiplica(x, y - 1);
    return cal;
}//função

int main(){
    int x, y;
    printf("\nDigite um valor para x: ");
    scanf("%d", &x);
    printf("\nDigite um valor para y: ");
    scanf("%d", &y);
    
    //chamada de função
    multiplica(x, y);
    printf("\nResultado da multiplicacao: %d\n", multiplica(x, y));
}//main
