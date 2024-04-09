//#include "main.c"
#include "produto.h"

#include <stdio.h>
#include <stdlib.h>

Produto *cadastrar_produto(Produto *lista_produtos) {

  int id;

  Produto *novo_produto = (Produto *)malloc(sizeof(Produto));
  if (novo_produto == NULL) {
    printf("Erro de alocação de memória.\n");
    exit(1);
  }

  printf("Digite o ID do produto: ");
  scanf("%d", &id);

  if (id < 0) {
    printf("ID invalido tente novamente\n\n");
    return cadastrar_produto(lista_produtos);
  }

  Produto *temp = lista_produtos;
  while (temp != NULL) {
    if (temp->id == id) {
      printf("ID já cadastrado, digite outro ID: \n");
      return cadastrar_produto(lista_produtos);;
    }
    temp = temp->proximo;
  }

  novo_produto->id = id;
  printf("Digite o nome do produto: ");
  scanf("%s", novo_produto->nome);
  printf("Digite a quantidade do produto: ");
  scanf("%d", &novo_produto->quantidade);
  printf("Digite o preço do produto: ");
  scanf("%f", &novo_produto->preco);

  novo_produto->proximo = lista_produtos;
  return novo_produto;
}