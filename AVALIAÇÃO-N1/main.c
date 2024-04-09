/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                         Guilherme Gallo Migliorini     */
/*                                         Pedro Coelho do Nascimento     */
/*             Objetivo: Cadastro de Produtos                             */
/*             Paradigama: programação modular (lista ligada)             */
/*                                                                        */
/*                                                         Data:08/04/2024*/
/*------------------------------------------------------------------------*/ 

#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

#include "busca.h"
#include "entrada.h"
#include "alteracao.h"

int main(void) {
  
  Produto* lista_produto = NULL;
  int opt, id;
  Produto* produto;

  do{
    printf("---Gerenciamento de Estoque---\n");
    printf("1- Cadastro Produto\n2- Busca Produto por ID\n3- Alterar Estoque\n0- Sair\n");
    printf("Escolha uma Opção: "); scanf("%d", &opt);

  switch (opt){
    case 1: lista_produto = cadastrar_produto(lista_produto);
    break;
    case 2:
      printf("Digite o ID do produto a ser buscado: ");
      scanf("%d", &id);
      produto = buscar_produto(lista_produto, id);
      if (produto != NULL) {
          printf("Produto encontrado:\n");
          printf("ID: %d, Nome: %s, Quantidade: %d, Preço: %.2f\n", produto->id, produto->nome, produto->quantidade, produto->preco);
      } else {
          printf("Produto não encontrado.\n");
      }
      break;
    case 3: printf("Digite o ID do produto cuja quantidade deseja alterar: ");
      scanf("%d", &id);
      produto = buscar_produto(lista_produto, id);
      if (produto != NULL) {
          alterar_quantidade(produto);
          printf("Quantidade do produto alterada com sucesso.\n");
      } else {
          printf("Produto não encontrado.\n");
      }
      break;
    };

  }while(opt);
  printf("Obrigado por usar o Programa! :D");
  return 0;
  exit(0);
}



