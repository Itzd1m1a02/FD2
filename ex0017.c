/**
 * @file ex0017.c
 * @author dimitri maia
 * @brief 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * Um problema típico em ciência da computação consiste em
converter um número da sua forma decimal para binária. Crie um
algoritmo recursivo para resolver esse problema.
 Solução trivial: x=0 quando o número inteiro já foi convertido para
binário
 Passo da recursão: saber como x/2 é connvertido. Depois, imprimir um
dígito (0 ou 1) dado o sucesso da divisão  
 */

#include <stdio.h>
#include <stdlib.h>

int binario(int x){
    if (x == 0) return 0;
    else if (x == 1) return 1;
    else return binario(x) % 2; 
}

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("O numero %d em binario e: ",num ,binario(num));
    return 0;
}
