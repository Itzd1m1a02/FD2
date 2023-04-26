/**
 * @file listaextra5.c
 * @author dimitri maia (dimitrimaia39@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * Crie um programa que gerencie um cadastro de materiais para obras disponíveis em um fornecedor. Cada material contém: nome (tamanho máximo 40 caracteres), 
 * quantidade (int) e preço (float) de no máximo 15 produtos. O programa deve possuir um menu para que o usuário do programa consiga manipular os cadastros. 
 * Nesse menu

a) Ao digitar (I), deve-se realizar inserção de um material na primeira posição que estiver livre;
b) Ao digitar (R), deve-se remover o material pelo índice (a ser fornecido pelo usuário );
c) Ao digitar (L), deve-se listar todos os cadastros não vazios;
d) Ao digitar (P), deve-se solicitar o nome de um material e exibir a quantidade e o preço;
e) Ao digitar (V), deve-se listar todos os produtos que tenham a quantidade igual a 0;
f) Ao digitar (S), deve sair do programa.

Obs: Cada opção do menu deve ser implementada em uma função diferente. Após cada função o menu deve ser reexibido (Exceto opção S)
Não utilize variáveis globais. Utilize passagem de parâmetros quando necessário.
Não se esqueça de criar um método para gerenciar qual posição do vetor está vazia ou não. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

typedef struct{
    char nome[40];
    int quantidade;
    float preco;
}Material;

void String(char string[], int tamanho){
    setbuf(stdin, NULL);
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
}

void add_material(Material material[], int i){
    if(i <= 15){
        printf("\n\nDigite o nome do produto: ");
        String(material[i].nome, 40);
        printf("\nDigite a quantidade de produtos: ");
        scanf("%d", &material[i].quantidade);
        printf("\nDigite o preco do material: ");
        scanf("%f", &material[i].preco);
        setbuf(stdin, NULL);
    }//if
    else{ 
        printf("\nO valor utrapasso o limite de quantidade\n\n");
        lista(material);    
    }//else
}//add

void remove_material(Material material[], int j){
    for (int i = 0; i < j; i++){
        if(j == i) material[i].quantidade = -1;
    }//for
}//função

void lista(Material material[]){
    for (int i = 0; i < 15; i++){
        if(material[i].quantidade != -1){
            printf("Nome[%d]: %s, quantidade: %d, valor do material: %.2f\n\n", i, material[i].nome, material[i].quantidade, material[i].preco);
        }//if
    }//for
}//função

int main(){
    Material material[15];
    char opcao;
    int i = 0;

    //coloca -1 em todas as possições da estrutura
    for (int j = 0; j < 15; j++){
        material[j].quantidade = -1;
    }//for
    setbuf(stdin, NULL);
    
    //loop infinito
    while (true){
        setbuf(stdin, NULL);
        printf("\nSUA OPCAO: ");
        scanf("%s", &opcao);
        setbuf(stdin, NULL);

        switch (opcao){
        case 'i':
        case 'I':
            add_material(material, i);
            break;

        case 'r':
        case 'R':
            int j;
            printf("\n\nDigite a posição que ira ser apagada: ");
            scanf("%d", &j);
            remove_material(material ,j);
            break;
        
        case 'l':
        case 'L':
            lista(material);
        default:
            break;
        }//switch
        i++;
    }//while
}//main
