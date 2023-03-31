/**
 * @file ex0016.c
 * @author dimitri maia
 * @brief 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 * Faça uma função recursiva que retorne o n-ésimo termo da sequência de
Fibonacci, sendo que n é recebido por parâmetro. Utilize essa função para
desenvolver um programa que mostre no main() os n termos dessa
sequência na tela, a partir do valor de n recebido pelo teclado. Sabe-se que
o 1º termo é 0 e o 2º termo é 1.
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}//fibonacci

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++){
        printf("\nO termo[%d] e: %d\n",i , fibonacci(i));
    }//for
    return 0;
}
