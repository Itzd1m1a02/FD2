/**
 * @file ex0013.c
 * @author dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 * função que retorna um fatorial de modo recursivo
 */

#include <stdio.h>
#include <stdlib.h>

int fatorialRecursivo(int x);

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    //chamada de função
    fatorialRecursivo(num);
    printf("\nResultado do fatorial --> %d\n", fatorialRecursivo(num));
}//main

int fatorialRecursivo(x){
    int cal;
    if(x == 1) return 1;
    else cal = x * fatorialRecursivo(x - 1);
    return cal;
}//função