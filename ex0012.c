/**
 * @file ex0012.c
 * @author dimitri maia (dimitrimaia39@.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *

Crie um Sistema de Gerenciamento de Bandas seguindo os seguintes
passos:
 a) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve
ter o nome da banda, que tipo de música ela toca, o número de integrantes e em que
posição do ranking essa banda está dentre as suas 5 bandas favoritas;
 b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo
passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
 c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu
programa deve exibir informações da banda cuja posição no seu ranking é a que foi
solicitada pelo usuário;
 d) Crie uma função que peça ao usuário um tipo de música e exiba as bandas com
esse tipo de música no seu ranking.
 e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está
entre suas bandas favoritas ou não;
 f) Agora junte tudo e crie um menu com as opções de preencher as estruturas e
todas as opções das questões passadas.

 */

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2

typedef struct{
    char nome_banda[50];
    char tipo_music[50];
    int participantes;
    int rank;
}Bandas;

void DadosBandas(Bandas bandas[]){
    for (int i = 0; i < MAX; i++){
        printf("\n\nDigite o nome da banda[%d]: ");
        fgets(bandas[i].nome_banda, 50, stdin);
        bandas[i].nome_banda[strcspn(bandas[i].nome_banda, "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("\nDigite o tipo de musicas que a banda toca: ");
        fgets(bandas[i].tipo_music, 50, stdin);
        bandas[i].tipo_music[strcspn(bandas[i].tipo_music, "\n")] = '\0';
        setbuf(stdin, NULL);
        do{
            printf("\nDigite o numero de participantes da banda: ");
            scanf("%d", &bandas[i].participantes);
        }while(bandas[i].participantes < 0);
        setbuf(stdin, NULL);
        do{
            printf("\nDigite o rank da banda: ");
            scanf("%d", &bandas[i].rank);
        }while(bandas[i].rank < 0);
        setbuf(stdin, NULL);
    }//for
}//função

int main(){
    Bandas bandas[MAX];
    DadosBandas(bandas);
}//main
