/**
 * @file ex0008.c
 * @author Dimitri Maia (dimitrimaia39@gmail .com)
 * @brief 
 * @version 0.1
 * @date 2023-03-17
 * @copyright Copyright (c) 2023
 *  
    Elabore uma função que receba por parâmetro o sexo (caractere) e a
    altura de uma pessoa (real), calcule e retorne seu peso ideal. Para isso,
    utilize as fórmulas a seguir.
     Para homens: (72.7 * altura) - 58
     Para mulheres: (62.1 * altura) - 44.7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    float altura;
    char sexo[20];
}Paciente;

float Mmc(Paciente paci){
    float cal;
    if(paci.sexo == 'homen'){
        cal = (72.7 * paci.altura) - 58;
    }else{
        cal = (62.1 * paci.altura) - 44.7;
    }//else
    return cal;
}//função

int main(){
    Paciente paci;
    printf("Digite o nome do paciente: ");
    fgets(paci.nome, 99, stdin);
    paci.nome[strcspn(paci.nome, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\n");
    printf("Digite a altura do paciente: ");
    scanf("%f", &paci.altura);
    setbuf(stdin, NULL);
    printf("\n");
    printf("Digite se e homem ou mulher: ");
    fgets(paci.sexo, 19, stdin);
    paci.sexo[strcspn(paci.sexo, "\n")] = '\0';
    setbuf(stdin, NULL);
    float peso_ideal = Mmc(paci);
    printf("\nO peso ideal desta pessoa e: %.2f kg\n", peso_ideal);
}//main