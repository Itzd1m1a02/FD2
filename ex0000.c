/*
A empresa Matrix precisa melhorar o sistema de
armazenamento de informacoes de seus funcionarios. MuriNeo, o gerente, entrou em contato contigo e
pediu para que voce seja o responsavel por desenvolver este novo sistema.
MuriNeo descreveu que as informacoes dos funcionarios estao armazenadas em um arquivo denominado
funcionarios.txt e que consta, na primeira linha, um numero que indica a quantidade de funcionarios.

Pediu para que se utilizasse estruturas de modo a representar as demais informacoes, conforme esquema-
tizadas abaixo:

i) CADASTRO: nome, endereco, salario, estado civil, idade, sexo;
ii) ENDERECO: rua, cidade, estado.
Continuou suas explicacoes mostrando que no arquivo funcionarios.txt, a partir da segunda linha, cada
linha contem os dados de um funcionario. As informacoes dos funcionarios estao dispostas como no
exemplo:
{Persephone Belluci; {Rua Revolutions,12 ; Apucarana; Parana} ; 3200; solteiro; 30; F}
Referente as respectivas informacoes:

{nome; {rua; cidade; estado} ; salario ; estado civil ; idade; sexo}
Exemplo de arquivo: encurtador.com.br/nqrMV

1

MuriNeo ainda esclareceu que seu sistema sera compartilhado com outras filiais da empresa que pos-
suem suas informacoes armazenadas de modo similar, ou seja, cada filial tem seu respectivo quadro de

funcionarios (e quantidade tambem!).
O programa devera:
• ordenar por salario (utilizando o algoritmo SelectSort), em ordem decrescente, imprimir em TELA
e em ARQUIVO.txt o nome o salario, a idade e o sexo do funcionario (nesta ordem).
Obs 1: Utilizar a main apenas para realizar as chamadas das funcoes e procedimentos dos itens listados
logo acima (ou seja, nao de implementar a main gigantesca).
Obs 2: Lembre-se de limpar a memoria antes de encerrar a execucao do programa (evitar memory leak).
Vocˆe precisa utilizar alocacao dinˆamica de memoria, certo?!
Obs 3: Utilizar passagem de parˆametros (argC e argV) para receber o nome do arquivo de entrada e de
saida.
*/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//struct de endereco
typedef struct{
    char Rua[100], Cidade[100], Estado[50];
}Endereco;

//struct de cadastros
typedef struct{
    char Nome[100], EstadoCivil[20], Sexo[10];
    int Idade, Salario;
    Endereco end;
}Cadastro;

void LeituraDados(){
     //variaveis
    FILE* arq;
    int i = 0;
    Cadastro *cad;

    //abre o arquivo
    arq = fopen("funcionarios3.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo de entrada!\n");
        exit(1);
    }//if

    //variavel que salva o numero de funcioanrios
    char aux1[6];
    char aux2[1000];

    //pega a primeira linha do arquivo
    fgets(aux1, 6, arq);
    int num_funci = atoi(aux1);
    printf("\nTOTAL DE FUNCIONARIOS: %d\n", num_funci);

    //aloca memoria para as struturas
    cad = (Cadastro*) malloc(num_funci * sizeof(Cadastro));

    //pega cada linha do arquivo e aloca em variaveis
    while(fgets(aux2, 1000, arq) != NULL){
        //{Persephone Belluci; {Rua Revolutions,12 ; Apucarana; Parana} ; 3200; solteiro; 30; F}
        sscanf(aux2, "{%[^;]; {%[^;] ; %[^;]; %[^}]} ; %d; %[^;]; %d; %[^}]}", cad[i].Nome, cad[i].end.Rua, cad[i].end.Cidade, cad[i].end.Estado, &cad[i].Salario, cad[i].EstadoCivil, &cad[i].Idade, cad[i].Sexo);
        i++;
    }//while

    //mostra os dados obtidos do arquivo
    for (i = 0; i < num_funci; i++){
        printf("\n[%d] Nome: %s, Endereco: %s, Cidade: %s, Estado: %s, Salario: %d, Estado-civil: %s, Idade: %d, Sexo: %s\n",i + 1, cad[i].Nome, cad[i].end.Rua, cad[i].end.Cidade, cad[i].end.Estado, cad[i].Salario, cad[i].EstadoCivil, cad[i].Idade, cad[i].Sexo);
    }//for
    
    //cahamda de função
    selectsort(cad, num_funci);

    //fecha o arquivo e libera memoria de alocação dinamica
    fclose(arq);
    free(cad);
}//função

void selectsort(Cadastro cad[], int tamanho){
    int i, j, min; 
    Cadastro aux;

    
    for (i = 0; i < (tamanho - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
      for (j = i+1; j < tamanho; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
        if (cad[j].Salario > cad[min].Salario) { //ordem decrecente
    min = j;
        }//if
      }//for
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
      if (i != min) {
        aux = cad[i];
        cad[i] = cad[min];
        cad[min] = aux;
      }//if
    }//for
  /* Imprime o vetor ordenado */
  printf("\n\n---------------lista-de-salarios----------------\n\n");
  for (i = 0; i < tamanho; i++) {
    printf ("\n[%d], nome do funcionario: %s, idade: %d, salario: %d, sexo: %s\n",i + 1, cad[i].Nome, cad[i].Idade, cad[i].Salario, cad[i].Sexo);
  }//for
}//função

int main(){
    LeituraDados();
    return 0;
}//main