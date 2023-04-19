/**
 * @file ex0022.c
 * @author dimitri maia
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * Elabora uma função que receba duas strings como parâmetros e
verifique se a segunda string está dentro da primeira. Para isso, utilize
apenas aritmética de ponteiros.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void String(char str[], int tamanho){
    setbuf(stdin, NULL);
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void contido_na_string(char x[], char y[]){
    int igual = 0;
    for(int i = 0; i < strlen(x) ; i++){
            if(y[0] == x[i]){
                for(int j = 0; j < strlen(y)-1 ;j++){
                    if(y[j] == x[i++]) igual++;
                }//for
            }//if
            if(igual == strlen(y)) break;
    }//for
    if(igual == strlen(y)) printf("o sobrenome consta no nome\n");
    else printf("o sobrenome nao consta no nome\n");
}//função

int main(){
    char nome_completo[30];
    char sobre_nome[20];

    printf("Digite o nome completo: ");
    String(nome_completo, 30);
    printf("\nDigite um sobrenome: ");
    String(sobre_nome, 20);

    contido_na_string(nome_completo, sobre_nome);
}