/**
 * @file ex0009.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 19-03-2023
 * 
 * @copyright Copyright (c) 2023
 * Escreva um procedimento que recebe por parâmetro as 3 notas de um
aluno e uma letra. Se a letra for A, o procedimento calcula a média
aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3
e 2) e se for S, a soma das notas. O valor calculado também deve ser
retornado e exibido na função main.

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

int main(){
    int notas[3];
    char tipo_media;
    for (int i = 0; i < 3; i++){
        printf("\nDigite a nota[%d]: ", i+1);
        scanf("%d", &notas[i]);
        setbuf(stdin, NULL);
    }//for
    printf("\nDigite o conseito: ");
    scanf("%c", &tipo_media);
    setbuf(stdin, NULL);
    float final = media(notas, tipo_media);
    printf("\no valor da media final do aluno e: %.2f", final);
}//main