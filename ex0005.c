/**
 * @file ex002.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 *  
 *  Crie um programa de cadastro que receba, armazene, e
    em seguida, exiba os dados de 5 pessoas.
     Cada pessoa possui: nome, idade, peso, data de nascimento,
    brasileiro ou estrangeiro. Caso seja Brasileiro, armazene o CPF,
    caso estrangeiro, armazene o passaporte.
     Regra: Utilize structs, typedef, union e enum.
 */
typedef struct{
    char nome[100];
    int idade, dia, mes, ano;
    float peso;
    enum {brasileiro, estrangeiro};
    union{int cpf, passaporte};
}Cadastro;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    Cadastro cadastro[5];
    int tipo_pessoa;
    for (int i = 0; i < 5; i++){
        do{
            printf("\nDigite 0 para brasileiro:");
            printf("\nDigite 1 para estrangeiro:");
            printf("\ndigite uma opcao: ");
            scanf("%d", &tipo_pessoa);
        }while (tipo_pessoa < 0 || tipo_pessoa > 1);
        setbuf(stdin, NULL);
        switch(tipo_pessoa){
        case brasileiro:
                printf("\nPessoa Brasileira\n\n");
                printf("\nDigite o nome do cidadao[%d]: ", i+1);
                fgets(cadastro[i].nome, 99, stdin);
                cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite a idade do cidadao: ");
                scanf("%d", &cadastro[i].idade);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite a data de nascimento do cidadao: ");
                scanf("%d/%d/%d", &cadastro[i].dia, &cadastro[i].mes, &cadastro[i].ano);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite o peso do cidadao: ");
                scanf("%f", &cadastro[i].peso);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite o CPF do cidadao: ");
                scanf("%d", &cadastro[i].cpf);
                setbuf(stdin, NULL);
                printf("\n\n");
            break;
        case estrangeiro:
                printf("\nPessoa estrangeira\n\n");
                printf("\nDigite o nome da pessoa[%d]: ", i+1);
                fgets(cadastro[i].nome, 99, stdin);
                cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite a idade da pessoa: ");
                scanf("%d", &cadastro[i].idade);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite a data de nascimento da pessoa: ");
                scanf("%d/%d/%d", &cadastro[i].dia, &cadastro[i].mes, &cadastro[i].ano);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite o peso da pessoa: ");
                scanf("%f", &cadastro[i].peso);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite o passaporte da pessoa: ");
                scanf("%d", &cadastro[i].passaporte);
                setbuf(stdin, NULL);
                printf("\n\n");
            break;
        default:
            break;
        }
    }//for
}//main