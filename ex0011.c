/**
 * @file ex0011.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * Reescreva o exercício anterior utilizando a estrutura horário
(contendo hora, minuto e segundo) e passando a estrutura por
referência. Utilize o seguinte protótipo da função:
void converteHorario(int total_segundos, Horario* hor) 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hora, min, seg;
}Horario;

void converteHorario(int total_seg, Horario* hor){
    (*hor).hora = total_seg / 3600;
    int resto = total_seg % 3600;
    (*hor).min = resto / 60;
    (*hor).seg = resto % 60;
    
    printf("\nA quantidade de segundos fornecidas da: (%d:%d:%d)", (*hor).hora, (*hor).min, (*hor).seg);
} 

int main(){
    //variaveis
    Horario hor;
    int total_seg; 

    printf("\nDigite um total de segundos: ");
    scanf("%d", &total_seg);

    //chamada de função
    converteHorario(total_seg, &hor);
}//main
