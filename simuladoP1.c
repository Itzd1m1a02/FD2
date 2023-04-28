/**
 * @file test.c
 * @author Dimitri Maia , Dimitrimaia39@gmail.com
 * @brief 
 * @version 0.1
 * @date 20-04-2023
 * 
 * @copyright Copyright (c) 2023
Você foi contratado pela Riot Games para elaborar partes do sistema sistema de Ranking do League of Legends. Para isso:

f) Utilizando uma função recursiva, calcule a soma de todas as partidas (vitórias e derrotas) de todos os jogadores.

Cada um dos itens de B a E deve ser implementada em uma função diferente.
Não é permitido o uso de variáveis globais.
Nas funções extras, caso necessário, utilize parâmetros adicionais.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a) Defina um tipo e estrutura para salvar os dados de jogadores para um Ranking.
//Cada jogador possui: nome, vitórias, derrotas, tier(nível) e pontos.
//Os tiers são: Bronze, Prata, Ouro, Platina, Diamante e Desafiante. Para organizar os níveis utilize uma enumeração.
typedef struct{
  char Nome_joagador[30];
  float partidas_vitoria;
  float partidas_derrotas;
  int partidas_pontos;
  float winrate;
  int tier;//auxiliar
  enum {Bronze = 1, Prata, Ouro, Platina, Diamante, Desafiante}elo;
}Jogador;

void String(char str[], int tamanho){
  setbuf(stdin, NULL);
  fgets(str, tamanho, stdin);
  str[strcspn(str, "\n")] = '\0';
}//manipula string

void informcao(){
  printf("\n1 -  Bronse\n2 - Prata\n3 - Ouro\n4 - Platina\n 5 - Diamante\n6 - Desafiante\n");
}//função

//b) Receba do teclado e armazene os dados de 6 jogadores. Não devem ser permitidos valores negativos, novos valores devem ser solicitados caso necessário.
void Dados_Jogador(Jogador jor[]){
  for (int i = 0; i < 6; i++){
    printf("\n\nDigite o nome do jogador[%d]: ", i+1);
    String(jor[i].Nome_joagador, 30);
    printf("\nDigite a quantidade de vitorias do jogador[%d]: ", i+1);
    scanf("%f", &jor[i].partidas_vitoria);
    setbuf(stdin, NULL);
    printf("\nDigite a quantidade de derrotas do jogador[%d]: ", i+1);
    scanf("%f", &jor[i].partidas_derrotas);
    setbuf(stdin, NULL);
    printf("\nDigite a quantidade de pontos do jogador[%d]: ", i+1);
    scanf("%d", &jor[i].partidas_pontos);
    setbuf(stdin, NULL);

    do{
      informcao();
      printf("\nDigite o Tier para o jogador: ");
      scanf("%d", &jor[i].tier);
      setbuf(stdin, NULL);
    }while(jor[i].tier < 0 || jor[i].tier > 6);
  }//for 
}//função

//c) Exiba uma tabela alinhada com o nome e a taxa de vitórias (winrate) de cada jogador
// winrate = vitórias / (vitórias+derrotas) * 100
// Cada calculo deve ser feito por meio de uma função adicional que recebe o número de vitórias e derrotas via cópia
// retorna o winrate
void cal(Jogador jor[]){
  for (int i = 0; i < 6; i++){
    jor[i].winrate = ((jor[i].partidas_vitoria / (jor[i].partidas_vitoria + jor[i].partidas_derrotas)) * 100);
  }//for
}//função
void Winrate(Jogador jor[]){
  cal(jor);
  printf("\n\n================================================================================================================================\n\n");
  for (int i = 0; i < 6; i++){
    printf("\n\nJogador %d: Nickname: %s Winrate: %.2f%%\n",i+1, jor[i].Nome_joagador,jor[i].winrate);
  }//for
}//função

//d) Exiba uma tabela com os líderes (maior número de pontos) de cada um dos níveis. Para isso, faça uma função extra que receba um tier e retorne uma estrutura do tipo Jogador com os dados do líder.

Jogador liderTier(Jogador jor[], int tier){ 
  int maior = 0;
  for (int i = 0; i < 6; i++){
    if(jor[i].tier == tier)
      if(jor[maior].winrate < jor[i].winrate) maior = i;
  }//for
  return jor[maior];
}//função
void exibelideres(Jogador jor[]){
  Jogador aux[6];
  for (int i = 0; i < 6; i++){
    aux[i] = liderTier(jor, jor[i].tier);
  }//for
  
  printf("\n\n================================================================================================================================\n\n");

  for (int i = 0; i < 6; i++){
    if(aux[i].tier == 1) printf("\n\nTop tier: BRONZE Nickname: %s, Winrate: %.2f\n\n", aux[i].Nome_joagador,jor[i].winrate);
    else if(aux[i].tier == 2) printf("\n\n Top tier: PRATA Nickname: %s, Winrate: %.2f\n\n", aux[i].Nome_joagador,jor[i].winrate);
    else if(aux[i].tier == 3) printf("\n\nTop tier OURO: Nickname: %s, Winrate: %.2f\n\n", aux[i].Nome_joagador, jor[i].winrate);
    else if(aux[i].tier == 4) printf("\n\n Top Tier PLATINA: Nickname: %s, Winrate: %.2f\n\n", aux[i].Nome_joagador, jor[i].winrate);
    else if(aux[i].tier == 5) printf("\n\n Top tier: DIAMANTE:  Nickname: %s, Winrate: %.2f\n\n", aux[i].Nome_joagador, jor[i].winrate);
    else printf("\n\n Top tier: DESAFIANTE: Nickname: %s, Winrate: %.2f\n\n", aux[i].Nome_joagador, jor[i].winrate); 
  }//for
}//função

//e) Faça a busca de um jogador pelo nome digitado. A busca deve ser feita por uma função adicional que recebe o nome e retorna os dados de vitórias, derrotas, tier e pontos via referência.
char elo(Jogador jor){
  if(jor.tier == 1) printf("\n\nNickname: %s, Vitorias: %.1f Derrotas: %.1f,tier: BRONZE, pontos totais: %d\n\n",jor.Nome_joagador, jor.partidas_vitoria, jor.partidas_derrotas, jor.partidas_pontos);
  else if(jor.tier == 2) printf("\n\nNickname: %s, Vitorias: %.1f Derrotas: %.1f,tier: PRATA, pontos totais: %d\n\n",jor.Nome_joagador, jor.partidas_vitoria, jor.partidas_derrotas, jor.partidas_pontos);
  else if(jor.tier == 3) printf("\n\nNickname: %s, Vitorias: %.1f Derrotas: %.1f,tier: OURO, pontos totais: %d\n\n",jor.Nome_joagador, jor.partidas_vitoria, jor.partidas_derrotas, jor.partidas_pontos);
  else if(jor.tier == 4) printf("\n\nNickname: %s, Vitorias: %.1f Derrotas: %.1f,tier: PLATINA, pontos totais: %d\n\n",jor.Nome_joagador, jor.partidas_vitoria, jor.partidas_derrotas, jor.partidas_pontos);
  else if(jor.tier == 5) printf("\n\nNickname: %s, Vitorias: %.1f Derrotas: %.1f,tier: DIAMANTE, pontos totais: %d\n\n",jor.Nome_joagador, jor.partidas_vitoria, jor.partidas_derrotas, jor.partidas_pontos);
  else return printf("\n\nNickname: %s, Vitorias: %.1f Derrotas: %.1f,tier: DESAFIANTE, pontos totais: %d\n\n",jor.Nome_joagador, jor.partidas_vitoria, jor.partidas_derrotas, jor.partidas_pontos);
}//função aux
Jogador acho(Jogador jor[], char nome[]){
  int achou = 0;
  for (int i = 0; i < 6; i++){
    if(strcasecmp(nome, jor[i].Nome_joagador) == 0){
      elo(jor[i]);
      achou++;
    }//if
  }//for
  if(achou == 0) printf("\n\nNao foi possivel achar o jogador solicitado\n\n");
}//função aux
void procurar(Jogador jor[]){
  char nome[30];

  printf("\n\nDigite o nome do JOGADOR que procura: ");
  String(nome, 30);
  acho(jor, nome);
}//função

//f) Utilizando uma função recursiva, calcule a soma de todas as partidas (vitórias e derrotas) de todos os jogadores.
float somatudo(float resultado, float vitoria, float derrota, int cont){
  if(cont == 1) return resultado;
  else return somatudo(vitoria + derrota, vitoria, derrota, cont - 1);
}//funação

int main(){
  float aux[6];
  int soma;
  Jogador jor[6];
  Dados_Jogador(jor);
  Winrate(jor);
  exibelideres(jor);
  procurar(jor);

  for (int i = 0; i < 6; i++){
    aux[i] = somatudo(0 ,jor[i].partidas_vitoria, jor[i].partidas_derrotas, 2);
  }//for
  for (int i = 0; i < 6; i++){
    soma = soma + aux[i];
  }//for
  
  prinf("Total de partidas de todos os jogadores: %d", soma);
}//main