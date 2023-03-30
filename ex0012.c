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
 */

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 2

typedef struct{
    char nome_banda[50];
    char tipo_music[50];
    int participantes;
    int rank;
}Bandas;

/*a) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve
ter o nome da banda, que tipo de música ela toca, o número de integrantes e em que
posição do ranking essa banda está dentre as suas 5 bandas favoritas; */
void DadosBandas(Bandas bandas[]){
    for (int i = 0; i < MAX; i++){
        printf("\n\nDigite o nome da banda[%d]: ", i + 1);
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
        }while(bandas[i].participantes <= 0);
        setbuf(stdin, NULL);
        do{
            printf("\nDigite o rank da banda: ");
            scanf("%d", &bandas[i].rank);
        }while(bandas[i].rank <= 0 || bandas[i].rank > 5);
        setbuf(stdin, NULL);
    }//for
    setbuf(stdin, NULL);
}//função

/*b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo
passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.*/
void exibeDados(Bandas bandas[]){
    for (int i = 0; i < MAX; i++){
        printf("\nNome da banda: %s\n", bandas[i].nome_banda);
        printf("Tipo de musica: %s\n", bandas[i].tipo_music);
        printf("Numero de participantes da banda: %d\n", bandas[i].participantes);
        printf("Rank da banda: %d\n\n", bandas[i].rank);
    }//for
    setbuf(stdin, NULL);
}//função

/*c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu
programa deve exibir informações da banda cuja posição no seu ranking é a que foi
solicitada pelo usuário;*/
void rank(Bandas bandas[]){
    int achou = 0;
    int procura_rank;

    printf("\nProcure um rank entre 1 e 5: ");
    scanf("%d", &procura_rank);

    for (int i = 0; i < MAX; i++){
        if(procura_rank == bandas[i].rank){
            printf("\nNome da banda: %s\n", bandas[i].nome_banda);
            printf("Tipo de musica: %s\n", bandas[i].tipo_music);
            printf("Numero de participantes da banda: %d\n", bandas[i].participantes);
            printf("Rank da banda: %d\n\n", bandas[i].rank);
            achou++;
        }//if
    }//while
    if(achou == 0){
        printf("\nO rank solicitado nao existen\n\n");
    }//else
    setbuf(stdin, NULL);
}//função

/*d) Crie uma função que peça ao usuário um tipo de música e exiba as bandas com
esse tipo de música no seu ranking.*/
void tipomusic(Bandas bandas[]){
    char aux[20];
    int achou = 0;

    printf("Digite um tipo de musica: ");
    fgets(aux, 20, stdin);
    aux[strcspn(aux, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < MAX; i++){
        if(strcmp(bandas[i].tipo_music, aux) == 0){
            printf("\nNome da banda: %s\n", bandas[i].nome_banda);
            printf("Numero de participantes da banda: %d\n", bandas[i].participantes);
            printf("Rank da banda: %d\n\n", bandas[i].rank);
            achou++;
        }//if
    }//for
    if(achou == 0){
        printf("\nO tipo de musica solicitado nao existe\n\n");
    }//else
    setbuf(stdin, NULL);
}//função

/*e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está
entre suas bandas favoritas ou não;*/
void bandaFavorita(Bandas bandas[]){
    char aux[40];
    int achou = 0;

    printf("Digite o nome de uma banda de musica: ");
    fgets(aux, 40, stdin);
    aux[strcspn(aux, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < MAX; i++){
        if(strcmp(bandas[i].nome_banda, aux) == 0){
            printf("Tipo de musica: %s\n", bandas[i].tipo_music);
            printf("Numero de participantes da banda: %d\n", bandas[i].participantes);
            printf("Rank da banda: %d\n\n", bandas[i].rank);
            achou++;
        }//if
    }//for
    if(achou == 0){
        printf("\nA banda solicitada nao existe, entre os favoritos\n\n");
    }//else
    setbuf(stdin, NULL);
}//função

/*f) Agora junte tudo e crie um menu com as opções de preencher as estruturas e
todas as opções das questões passadas.*/
void menu(Bandas bandas[]){
    int opcion;
    while (true){
    informacao();
    printf("\n\nDigite uma opcao: ");
    scanf("%d", &opcion);
    printf("\n\n");
        switch(opcion){
        case 1:
            setbuf(stdin, NULL);
            rank(bandas);        
            break;
        case 2:
            setbuf(stdin, NULL);
            tipomusic(bandas);
            break;
        case 3:
            setbuf(stdin, NULL);
            bandaFavorita(bandas);
        case 4:
            exit(1);
            break;
        }//switch
    }//while
    
    setbuf(stdin, NULL);
}//função

void informacao(){
    printf("\nDigite 1 para verificar o rank das bandas\nDigite 2 para verificar o tipo de muisca das bandas\nDigite 3 para verificar se sua banda favorita esta no podio\nDigite 4 para finalizar o programa\n\n");
}//função

int main(){
    Bandas bandas[MAX];
    DadosBandas(bandas);
    exibeDados(bandas);
    menu(bandas);
}//main