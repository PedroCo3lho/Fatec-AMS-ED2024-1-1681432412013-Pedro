#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    int id;
    char nome[50];
    int quantidade;
    float preco;
    struct Produto* proximo;
} Produto;

Produto* cadastrar_produto(Produto* lista_produtos);
Produto* buscar_produto(Produto* lista_produtos, int id);
void alterar_quantidade(Produto* produto);
void listar_produtos(Produto* lista_produtos);

#endif
