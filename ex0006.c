/**
 * @file ex001.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 *  Crie uma enumeração representando os meses do ano.
    Agora, escreva um programa que leia um valor inteiro do
    teclado e exiba o nome do mês correspondente e a
    quantidade de dias que ele possui.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {janeiro = 1, fevereiro, marco, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro};

int main(){
    int num_mes;
    do{
        printf("\nDigite um numero de 1 a 12: ");
        scanf("%d", &num_mes);
    }while (num_mes < 0 || num_mes > 12);
    switch (num_mes){
    case janeiro:
        printf("mes de janeiro, tem 31 dias\n");
        break;
    case fevereiro:
        printf("mes de fevereiro, tem de 28 a 29 dias\n");
        break;
    case marco:
        printf("mes de marco, tem 31 dias\n");
        break;
    case abril:
        printf("mes de abril, tem 30 dias\n");
        break;
    case maio:
        printf("mes de maio, tem 31 dais\n");
        break;
    case junho:
        printf("mes de junho, tem 30 dias\n");
        break;
    case julho:
        printf("mes de julho, tem 31 dias\n");
        break;
    case agosto:
        printf("mes de agosto, tem 31 dias\n");
        break;
    case setembro:
        printf("mes de setembro, tem 30 dias\n");
        break;
    case outubro:
        printf("mes de outubro, tem 31 dias\n");
        break;
    case novembro:
        printf("mes de novembro, tem 30 dias\n");
        break;
    case dezembro:
        printf("mes de dezembro, tem 31 dias\n");
        break;
    default:
        exit(1);
        break;
    }//switch
}//main