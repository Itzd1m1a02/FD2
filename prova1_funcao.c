/* *
* @arquivo prova1_funcao.c
* @autor dimitri maia (dimitrimaia39@gmail.com)
* @apresentação
* @versão 0.1
* @data 2023-03-03
*
* @copyright Copyright (c) 2023
*
a) Faça um programa que receba os dados das 5 cidades: nome(strings), a quantidade de servidores ativos e a quantidade de servidores com falha
( salvas nas duas primeiras vozes de uma matriz de inteiros 5x3). Os valores não podem ser negativos, solicite novos valores enquanto o
usuário digite valores inválidos.
b) Usando estruturas de repetição, calcule a quantidade total de servidores em cada cidade e salve na última coluna da matriz;
c) Exiba em formato de tabela (com colunas alinhadas separadas por | ) os nomes, as 3 bandejas de servidores de todas as cidades.
d) Receba um nome de uma cidade e busque ela na lista, todos os dados de seus servidores
(apenas 1 vez). Exiba uma mensagem informando também caso não encontre o nome buscado.
e) Exiba o nome da cidade e a porcentagem da cidade que tem o maior percentual de servidores com problemas (duas casas decimais).
f) Utilizar estrutura de repetição, calcular e exibir o percentual total de servidores ativos e de servidores com problemas.
g) Acrescente o texto "Defeated" ao final da string de nome de todas as cidades que têm o número de servidores com problemas
maiores que os servidores ativos. Em seguida exiba o nome de todas as cidades (alteradas ou não).
Ex: "São Paulo" -> "São Paulo Derrotado"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rec_dados(char cidades[5][21], int servidores[5][3]){
    for(int i = 0 ; i < 5 ; i++){
        setbuf (stdin, NULL );
        printf ("Digite o nome da CIDADE %d : " ,i+ 1 );
        fgets (cidades[i], 20 , stdin);
        cidades[i][strcspn(cidades[i],"\n")]='\0';
        setbuf (stdin, NULL);
        
        printf ("digite a quantidade de servidores ATIVOS: " );
        scanf ( "%d", &servidores[i][0]);
        setbuf (stdin, NULL);

        printf ("digite a quantidade de servidores INATIVOS: " );
        scanf ( "%d", &servidores[i][1]);
        setbuf (stdin, NULL);
        printf("\n");
    } // for
}

void cal_total_serv(int servidores[5][3]){
    for (int i = 0 ; i < 5 ; i++){
        servidores[i][2] = servidores[i][0] + servidores[i][1];
    }
}

void exibe_tab(char cidades[5][21], int servidores[5][3]){
    for (int i = 0 ; i < 5 ; i++){
        printf ( "| %-20s | %4d | %4d | %4d |\n " , cidades[i], servidores[i][0], servidores[i][1], servidores[i][2]);
    }
}

void busca_cidades(char cidades[5][21], int servidores[5][3]){
    char buscar[21];
    int achou = 0 ;
    printf ("digite o nome da cidade a ser buscada: " );
    fgets(buscar, 20, stdin);
    buscar[strcspn(buscar,"\n")]='\0';
    setbuf (stdin, NULL);

    for (int i = 0 ; i < 5 ; i++){
        if (strcasecmp(buscar, cidades[i]) == 0){
            printf ("esta na lista!\n" );
            printf ("| %-20s | %4d | % 4d | %4d |\n " , cidades[i], servidores[i][0], servidores[i][1], servidores[i][2]);
            achou++;
        }
    }
    if (achou == 0) printf ("cidade nao esta na lista\n" );
}

void porcentagem_cidades(char cidades[5][21], int servidores[5][3]){
    float calculo[5][1];
    //servidores com falha
    printf("SERVIDORES COM FALHA:\n");
    for (int i = 0 ; i < 5 ; i++){
        calculo[i][0] = ((float)servidores[i][1] / (float)servidores[i][2]) * 100;
        if(i <= 5) printf ( "| %-20s | %4d | %4d | %4d | %.2f%%\n " , cidades[i], servidores[i][0], servidores[i][1], servidores[i][2], calculo[i][0]);
    }
    printf("\n\n");
    //servidores ativos
    printf("SERVIDORES ATIVOS:\n");
    for (int i = 0 ; i < 5 ; i++){
        calculo[i][0] = ((float)servidores[i][0] / (float)servidores[i][2]) * 100;
        if(i <= 5) printf ( "| %-20s | %4d | %4d | %4d | %.2f%%\n " , cidades[i], servidores[i][0], servidores[i][1], servidores[i][2], calculo[i][0]);
    }
}

void verifica_cidades(char cidades[5][21], int servidores[5][3]){
    for (int i = 0; i < 5; i++){
        if(servidores[i][0] < servidores[i][1]) strcat(cidades[i], " DERROTADA");
        if(i <= 5){ 
            printf("Cidades com maiores falhas: "); 
            printf("%s\n", cidades[i]);
        }//if
    }
}

int main(){
    char cidades[5][21];
    int servidores[5][3];
    rec_dados(cidades, servidores);
    cal_total_serv(servidores);
    exibe_tab(cidades, servidores);
    busca_cidades(cidades, servidores);
    porcentagem_cidades(cidades, servidores);
    verifica_cidades(cidades, servidores);
    return 0;
}