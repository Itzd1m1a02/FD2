/**
 * @file ex0004.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 06-03-2023
 * 
 * @copyright Copyright (c) 2023
 * Faça um programa que controla o consumo de energia dos
   eletrodomésticos de uma casa e:
     Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras),
    potência (real, em kW) e tempo ativo por dia (real, em horas).

     Leia um tempo t (em dias), calcule e mostre o consumo total na casa e
    o consumo relativo de cada eletrodoméstico (consumo/consumo total)
    nesse período de tempo. Apresente este último dado em porcentagem.

    Consumo = (potência em watt/1000) x (tempo em horas) = total em kWh.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[16];
    float potencia;
    int tempo;
}Eletro;

void consumo(Eletro el[]){
    float cal[5], cal2[5];
    for (int i = 0; i < 5; i++){
         cal2[i] = el[i].tempo * 24;
    }//for
    for (int i = 0; i < 5; i++){
        cal[i] = (el[i].potencia / 1000) * cal2[i];
        printf("valor do cunsumo total do eletrodomestico[%d]: %.2f\n", i+1, cal[i]);
    }//for
}//função

int main(){
    Eletro eletro[5];
    for (int i = 0; i < 5; i++){
        printf("Digite o nome do eletrodomestico[%d]: ", i+1);
        fgets(eletro[i].nome, 15, stdin);
        eletro[i].nome[strcspn(eletro[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("\n");

        printf("Digite a potencia do eletro[%d]: ", i+1);
        scanf("%f", &eletro[i].potencia);
        setbuf(stdin, NULL);
        printf("\n");
        
        printf("Digite o tempo ativo do item em dia[%d]: ", i+1);
        scanf("%d", &eletro[i].tempo);
        int cal = eletro[i].tempo * 24;
        printf("\nO tempo de atividade do eletrodomestico e de %d horas\n", cal);
        setbuf(stdin, NULL);
        printf("\n\n");
    }//for

    consumo(eletro);
}//main
