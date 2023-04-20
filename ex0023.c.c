/**
 * @file test.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 20-04-2023
 * 
 * @copyright Copyright (c) 2023
 * Considere a seguinte declaração:
 int a, *b, **c, ***d;
 Escreva um programa que receba o valor de a, calcule e exiba:
 O dobro do valor a, utilizando o ponteiro b
 O triplo do valor a, utilizando o ponteiro c
 O quadruplo do valor a, utilizando o ponteiro d
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 2;
  //printf("Digite um numero: ");
  //scanf("%d",&a);

  int *b = 2*a; //duplo
  int **c = 3*a; //triplo
  int ***d = 4*a; //quadruplo

  printf("\n\no valor de a: %d, o dobro: %d, o triplo: %d, o quadruplo: %d\n\n", a, b, c, d);

}//main
