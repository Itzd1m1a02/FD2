/**
 * @file ex0011.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 19-03-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int fatorial(int x){
    int cal;
    if(x <= 1) return 1;
    else{
        cal =  x * fatorial(x - 1);
        return cal;
    }//recurção
}
int main(){
    int num;
    do{
        printf("Digite um numero: ");
        scanf("%d",&num);
    }while (num < 0);
    int resul = fatorial(num);
    printf("\nO fatoria de %d e: %d\n", num, resul);
}//main
