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
• ordenar por salario (utilizando o algoritmo Heapsort), em ordem decrescente, imprimir em TELA
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

//struct de cadastros
typedef struct{
    char Nome[100];
    char EstadoCivil[20];
    char Idade[10];
    char Sexo[10];
    char Salario[10];
}Cadastro;

//struct de endereco
typedef struct{
    char Rua[100];
    char Cidade[100];
    char Estado[50];
}Endereco;

void LeituraDados(){
     //variaveis
    FILE* arq;
    int i = 0;
    Cadastro *cad;
    Endereco *end;
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
    printf("O numero de funcionarios e: %d\n", num_funci);

    //aloca memoria para as struturas
    cad = (Cadastro*) malloc(num_funci * sizeof(Cadastro));
    end = (Endereco*) malloc(num_funci * sizeof(Endereco));

    while(fgets(aux2, 1000, arq) != NULL){
        sscanf(aux2, "{ %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^}] }", cad[i].Nome, end[i].Rua, end[i].Cidade, end[i].Estado, cad[i].Salario, cad[i].EstadoCivil, cad[i].Idade, cad[i].Sexo);
        i++;
    }//while

    i = 0;
    while(i < num_funci){
        printf("\nfuncionario[%d]{ nome: %s, endereco: %s, cidade: %s, estado: %s, salario: %s, estado civil: %s, idade: %s, sexo: %s}",i + 1, cad[i].Nome, end[i].Rua, end[i].Cidade, end[i].Estado, cad[i].Salario, cad[i].EstadoCivil, cad[i].Idade, cad[i].Sexo);
        i++;
    }//while

    fclose(arq);
    free(cad);
    free(end);
}

int main(){
    LeituraDados();
    return 0;
}//main