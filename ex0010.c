/**
 * @file ex0010.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 19-03-2023
 * 
 * @copyright Copyright (c) 2023
 *Faça uma função que receba a média final de um aluno
por parâmetro e retorne o seu conceito
 */
#include <stdio.h>
#include <stdlib.h>

float media(int notas[], char tipo_media){
    float cal = 0;
    switch (tipo_media){
    case 'a':
    case 'A':
        cal = (notas[0] + notas[1] + notas[2]) / 3;
        return cal;
        break;
    case 'p':
    case 'P':
        cal = ((notas[0]*5) + (notas[1]*3) + (notas[2]*2)) / 10;
        return cal;
        break;
    case 's':
    case 'S':
        for (int i = 0; i < 3; i++){
            cal = cal + notas[i];
        }//for        
        return cal;
        break;
    default:
        break;
    }//switch
}//função

char conseito(int media){
    if(media == 10 && media >= 9) return 'A';
    else if(media < 9 && media >= 7) return 'B';
    else if(media < 7 && media >= 5) return 'C';
    else{return 'D';};
}

int main(){
    int notas[3];
    char tipo_media;
    for (int i = 0; i < 3; i++){
        printf("\nDigite a nota[%d]: ", i+1);
        scanf("%d", &notas[i]);
        setbuf(stdin, NULL);
    }//for
    printf("\nDigite o tipo de calculo de media: ");
    scanf("%c", &tipo_media);
    setbuf(stdin, NULL);
    float final = media(notas, tipo_media);
    printf("\no valor da media final do aluno e: %.2f\n", final);
    char con = conseito(final);
    printf("\no aluno com media %.2f tem conseito %c\n", final, con);
}//main
