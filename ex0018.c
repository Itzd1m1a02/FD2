/**
 * @file ex0018.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 31-03-2023
 * 
 * @copyright Copyright (c) 2023
 * Considere a funcaox abaixo. O que essa função faz? Escreva
uma função não-recursiva que resolve o mesmo problema
int funcaox(int a){
 if(a <= 0) return 0;
 else return a + funcaox(a-1);
 */

#include <stdio.h>
#include <stdlib.h>

int funcaox(int a){
    if(a <= 0) return 0;
    else return a + funcaox(a - 1);
}//funcao

int somatorio_n (int a){
    for(int i = a; i >= 1; i--){
        a = a + (i - 1);
    }//for
    return a;
}//funcao

int main(void){
    int a;
    printf("Digite um numero: ");
    scanf("%d",&a);
    printf("\nO valor dado pela função recursiva e: %d\n", funcaox(a));
    printf("\nO valor dado pela função iterativa e: %d\n", somatorio_n(a));
    return 0;
}