/**
 * @file test.c
 * @author dimitri maia (Dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-12
 * 
 * @copyright Copyright (c) 2023
 * Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, 
 * idade e altura. Agora, escreva um programa que leia os dados de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2

typedef struct{
    char nome[50], esporte[30];
    int idade;
    float altura;    
}Atleta;

void String(char str[], int tamanho){
    setbuf(stdin, NULL);
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void Dados(){
    //struct
    Atleta at[MAX];
    for (int i = 0; i < MAX; i++){
        printf("\n\nDigite o nome do atleta[%d]: ", i+1);
        String(at[i].nome, 50);
        printf("\nDigite o nome do esporte do atleta[%d]: ", i+1);
        String(at[i].esporte, 30);
        printf("\nDigite a idade do atleta[%d]: ", i+1);
        scanf("%d", &at[i].idade);
        printf("\nDigite a altura do atleta[%d]: ", i+1);
        scanf("%f", &at[i].altura);
        setbuf(stdin, NULL);
    }
    Maisvelho(at);
}

void Maisvelho(Atleta at[]){
    int maior = 0;
    for (int i = 1; i < MAX; i++){
        if(at[maior].idade < at[i].idade) maior = i;
    }
    printf("\n\nO nome do atleta mais velho e: %s, com idade de %d, com altura %.2f que pratica: %s\n", at[maior].nome, at[maior].idade, at[maior].altura, at[maior].esporte);
    Maisalto(at);
}//função

void Maisalto(Atleta at[]){
    int maior = 0;
    for (int i = 1; i < MAX; i++){
        if(at[maior].altura < at[i].altura) maior = i;
    }
    printf("\n\nO nome do atleta mais alto e: %s, com idade de %d, com altura %.2f que pratica: %s\n", at[maior].nome, at[maior].idade, at[maior].altura, at[maior].esporte);
}

int main(){
    Dados();
}//main
