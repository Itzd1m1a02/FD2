/**
 * @file ex0001.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * @copyright Copyright (c) 2023
 * 
 *  Crie uma estrutura para representar as coordenadas de
    um ponto no plano (posições X e Y). Em seguida, declare
    e leia do teclado dois pontos e exiba a distância entre
    eles.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x, y;
}Pontos;

int main(){

    Pontos p1;
    Pontos p2;

    printf("Digite um valor para X1 e Y1: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Digite um valor para X2 e Y2: ");
    scanf("%f %f", &p2.x, &p2.y);

    float cal = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); 

    printf("distancia entre os pontos --> %.2f", cal);
    
    return 0;
}