/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Manipulação de Lista da Guiada e Struct          */
/*             Paradigama: programação estruturada                        */
/*                                                                        */
/* ~Pedro Coelho do Nascimento                             Data:02/04/2024*/
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct no {
  int id;
  struct no *prox;
};
typedef struct no No;

int menu();
void cadastro(No **lista);
int listar(No *lista);
int consultar(No *lista, int id);
void excluir(No **lista);

int main(void) {
  No *lista = NULL;
  int escolha;
  int id;
  do {
    escolha = menu();

    switch (escolha) {
    case 1:
      cadastro(&lista);
      break;
    case 2:
      printf("\nDigite o id para consulta: ");
      scanf("%d", &id);
      consultar(lista, id);
      break;
    case 3:
      excluir(&lista);
      break;
    case 4:
      listar(lista);
      break;
      case 5:
      printf("\nSaindo do programa...\n");
    }
  } while (escolha!=5);

  printf("Programa encerrado!\n");
  exit(0);
}

int menu() {
  printf("1 - Inserir ID\n");
  printf("2 - Consultar ID\n");
  printf("3 - Excluir ID\n");
  printf("4 - Listar\n");
  printf("5 - Sair\n\n");
  int escolha;
  printf("Escolha: ");  scanf("%d", &escolha);
  return escolha;
}

void cadastro(No **lista) {
  No *Lista = (No *)malloc(sizeof(No)); // aloca memoria para o novo no
  int id;
  if (!Lista) {
    exit(1);
  }

  printf("\nDigite o id: ");  scanf("%d", &id);

  No *temp = *lista; // temp recebe o endereço do primeiro elemento da lista
  while (temp != NULL) {
    if (temp->id == id) { // verifica se o id já existe
      printf("ID já cadastrado!\n\n");
      return;
    }
    temp = temp->prox; // temp recebe o endereço do proximo elemento da lista
  }

  Lista->id = id;       // recebe o id digitado pelo usuario
  Lista->prox = *lista; // o proximo elemento da lista recebe o endereço do
                        // primeiro elemento da lista
  *lista = Lista;
  printf("ID Cadastrado\n\n");
}

int listar(No *lista) {
  if (lista == NULL) {
    printf("\nNenhum ID cadastrado.\n\n");
    return 0;
  }
  while (lista != NULL) {
    printf("Id: %d\n", lista->id);
    lista = lista->prox;
  }
  return 1;
}

int consultar(No *lista, int id) {
  while (lista != NULL) {
    if (lista->id == id) {
      printf("ID Cadastrado! \nID: %d\n\n", lista->id);
      return 1;
    } else {
      lista = lista->prox;
    }
  }
  printf("ID Não Cadastrado! :(\n\n");
  return 0;
}

void excluir(No **lista) {
  int id, exc;

  if (*lista == NULL) {
    printf("Lista Vazia!\n\n");
    return;
  }
  
  printf("\nDigite o ID para exclusão: "); scanf("%d", &id);
  
  if (!consultar(*lista, id)) {// verifica se o id existe
    return;
  }
  
  printf("Excluir ID? (1-Sim/0-Não)\n"); scanf("%d", &exc);

  if (exc) {

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && atual->id != id) {
      anterior = atual;
      atual = atual->prox;
    }

    if (anterior == NULL) {
      *lista = atual->prox;
    } else {
      anterior->prox = atual->prox;
    }

    free(atual);
    printf("ID Excluido!\n\n");
  }
}