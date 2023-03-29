/**
 * @file ex0010.c
 * @author dimitrimaia39@gmail.com (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * Escreva um programa que receba um número inteiro
representando a quantidade total de segundos e, usando
passagem de parâmetros por referência, converta a
quantidade informada de segundos em Horas, Minutos e
Segundos. Imprima o resultado da conversão no formato
HH:MM:SS. Utilize o seguinte protótipo da função:
void converteHora(int total_segundos, int* hora, int* min, int* seg)
 */

#include <stdio.h>
#include <stdlib.h>

void converteHora(long int total_seg, int* hora, int* min, int* seg){
    *hora = total_seg / 3600;
    int resto = total_seg % 3600;
    *min = resto / 60;
    *seg = resto % 60;
    
    printf("\nA quantidade de segundos fornecidas da: (%d:%d:%d)", *hora, *min, *seg);
}//função

int main(){
    //variaveis
    long int total_seg; 
    int hora, min, seg;

    printf("\nDigite um total de segundos: ");
    scanf("%ld", &total_seg);

    //chamada de função
    converteHora(total_seg, &hora, &min, &seg);
}//main
