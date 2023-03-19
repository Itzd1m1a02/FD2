/**
 * @file ex0008.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 19-03-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int Maior(int num[]){
    int maior = num[0];
    for (int i = 0; i < 3; i++){
        if(maior < num[i]) maior = num[i];
    }
    return maior;
}

int main(){
    int num[3];
    for (int i = 0; i < 3; i++){
        printf("\nDigite um numero: ");
        scanf("%d", &num[i]);
    }//for
    int resul = Maior(num);
    printf("\n O maior numero e: %d", resul);
}