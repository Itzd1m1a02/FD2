/**
 * @file ex0002.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 04-03-2023
 * 
 * @copyright Copyright (c) 2023
 * Escreva um trecho de código para fazer a criação dos
novos tipos de dados conforme solicitado abaixo:
 Horário: composto de hora, minutos e segundos.
 Data: composto de dia, mês e ano.
 Compromisso: local, horário e texto que descreve o
compromisso.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    struct{
        int hora, min, seg;
    }Horario;
    struct{   
        int dia, mes, ano;
    }data;
    struct{ 
        char descricao[100], local[100];
    }Compromisso;     
}Calendario;

void informacoes(){
    printf("Digite 1 para definir um alarme\n");
    printf("Digite 2 para definir uma data\n");
    printf("Digite 3 para definir um compromisso\n");
    printf("Digite 4 para finalizar um programa\n\n");
}

int main(){
    Calendario calen;
    int opcao;

    while (true){
        printf("\n\n");
        informacoes();
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 4){
            printf("\n\n");
            informacoes();
            printf("Digite uma opcao: ");
            scanf("%d", &opcao);
        }//if
            switch (opcao){
            case 1:
                printf("\nDigite a hora os minutos e o segundos para definir o alarme: ");
                scanf("%d:%d:%d", &calen.Horario.hora, &calen.Horario.min, &calen.Horario.seg);
                printf("\n");
                printf("O alarme foi definido para %d:%d:%.2d", calen.Horario.hora, calen.Horario.min, calen.Horario.seg);
                break;
            case 2:
                printf("\nDigite a data da ocasiao: ");
                scanf("%d/%d/%d", &calen.data.dia, &calen.data.mes, &calen.data.ano);
                printf("\n");
                printf("A data foi definida para: %d/%d/%.4d", calen.data.dia, calen.data.mes, calen.data.ano);
                break;
            case 3:
                printf("\nDigite a hora os minutos e o segundos para definir o alarme: ");
                scanf("%d:%d:%2d", &calen.Horario.hora, &calen.Horario.min, &calen.Horario.seg);
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite o local da ocasiao: ");
                fgets(calen.Compromisso.local, 99, stdin);
                calen.Compromisso.local[strcspn(calen.Compromisso.local, "\n")] = '\0';
                setbuf(stdin, NULL);
                printf("\n");
                printf("Digite a descrisao da ocasiao: ");
                fgets(calen.Compromisso.descricao, 99, stdin);
                calen.Compromisso.descricao[strcspn(calen.Compromisso.descricao, "\n")] = '\0';
                setbuf(stdin, NULL);
                printf("\n");
                printf("Compromiso marcado com sucesso!");
                break;
            case 4:
                printf("\nFinalizando programa\n");
                return 0;
                break;
            }//switch
    }//while
}//main

