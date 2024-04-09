//#include "main.c"
#include "produto.h"

#include <stdio.h>
#include <stdlib.h>

void alterar_quantidade(Produto *produto) {
  int nova_quantidade;
  printf("Digite a nova quantidade para o produto %s: ", produto->nome);
  scanf("%d", &nova_quantidade);
  if (nova_quantidade < 0) {
    printf("Insira uma quantidad valida\n\n");
    return alterar_quantidade(produto);
  }
  produto->quantidade = nova_quantidade;
}