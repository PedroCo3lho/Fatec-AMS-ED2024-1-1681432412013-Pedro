/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                         Guilherme Gallo Migliorini     */
/*                                         Pedro Coelho do Nascimento     */
/*             Objetivo: Cadastro de Produtos                             */
/*             Paradigama: programação modular (lista ligada)             */
/*                                                                        */
/*                                                         Data:02/04/2024*/
/*------------------------------------------------------------------------*/ 

#include <stdio.h>
#include <stdlib.h>

struct No{
  int id;
  char nome[50];
  int qtn;
  double preco;
  struct No* prox;
};
//Cria um novo tipo de variavel ^^
typedef struct No no;

void cadastro();
void listar();
void excluir();

int main(void) {

  struct Produto *inicio = NULL;
  int opt;
  do{
    printf("Gerenciamento de Estoque\n");
    printf("1-Cadastro\n2-Listar\n3-Excluir\n0-Sair\n");
    scanf("%d", &opt);

  switch (opt){
    case 1: cadastro();
    break;
    case 2: listar();
    break;
    case 3: excluir();
    break;
    };
    
  }while(opt);
  printf("Obrigado por usar o Programa! :D");
  return 0;
  exit(0);

  
}

void cadastro(){
  
  no* Lista = (no*)malloc(sizeof(int));
  if(!Lista) exit(1);
  
  printf("Digite o id do Produto: ");   scanf("%d", &Lista->id);
  
  struct Produto *produto = inicio;
  while (ptr != null)
  
  
  printf("Digite o nome do Produto: "); scanf("%c",&Lista->nome);

  
}

void listar(){
  
}

void excluir(){
  
}


