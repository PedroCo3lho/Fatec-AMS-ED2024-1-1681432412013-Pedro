//#include "main.c"
#include "produto.h"

#include <stdio.h>
#include <stdlib.h>

Produto* buscar_produto(Produto* lista_produtos, int id) {
    Produto* atual = lista_produtos;
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
