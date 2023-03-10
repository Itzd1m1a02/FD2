/**
 * @file ex0003.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 05-03-2023
 * 
 * @copyright Copyright (c) 2023
 * Construa uma estrutura aluno com nome, curso e 4 notas,
média e situação. Leia as informações nome, curso e notas do
teclado, calcule a média e armazene a situação do aluno.
 media ≥ 7 → Aprovado;
 3 ≤ media < 7 → Exame;
 media < 3 → Reprovado;
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    int media;
}Aluno;


int main(){
    Aluno al[4];
    for (int i = 0; i < 4; i++){
        printf("Digite o nome do aluno[%d]: ", i+1);
        fgets(al[i].nome, 99, stdin);
        al[i].nome[strcspn(al[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("\nDigite a media do aluno[%d]: ",i+1);
        scanf("%d", &al[i].media);
        setbuf(stdin, NULL);
        printf("\n");
    }//for

    for (int i = 0; i < 4; i++){
        if(al[i].media >= 7) printf("O aluno %s esta APROVADO!\n", al[i].nome);
        else if(al[i].media >= 3 && al[i].media < 7) printf("O aluno %s esta de EXAME!\n", al[i].nome);
        else if(al[i].media < 3) printf("O aluno %s esta REPROVADO!\n", al[i].nome);
    }//for
    
    return 0;
}