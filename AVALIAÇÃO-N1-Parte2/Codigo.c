/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                         Guilherme Gallo Migliorini     */
/*                                         Pedro Coelho do Nascimento     */
/*             Objetivo: Cadastro de Pacotes                              */
/*             Paradigama: Alterar,Cadastrar e excluir(Não fisica)        */
/*             Com lista ligadas                                          */
/*                                                         Data:14/04/2024*/
/*------------------------------------------------------------------------*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct Pacote {
    int id;
    char cida_ori[50];
    char cida_dest[50];
    int status;
    char conteudo[50];
    struct Pacote* proximo;
} Pacote;

Pacote* cadastrar_pacote(Pacote *lista_pacotes);
void alterar_pacote(Pacote **lista_pacotes);
void consultar_pacote(Pacote *lista_pacotes);
void excluir_pacote(Pacote **lista_pacotes);

int id;

int main(void) {
    Pacote* lista_pacote = NULL;
    int opt;
    Pacote* pacote;

    do {
        printf("---Gerenciamento de Pacotes---\n");
        printf("1- Incluir Pacote\n2- Alterar Pacote\n3- Excluir Pacote\n4- Consultar Pacote\n0- Sair\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                lista_pacote = cadastrar_pacote(lista_pacote);
                break;
            case 2:
                alterar_pacote(&lista_pacote);
                break;
            case 3:
                excluir_pacote(&lista_pacote);
                break;
            case 4:
                consultar_pacote(lista_pacote);
                break;
        };

    } while (opt);

    printf("Obrigado por usar o Programa! :D\n");
    return 0;
}

Pacote* cadastrar_pacote(Pacote *lista_pacotes) {
    id += 2;

    Pacote *novo_pacote = (Pacote *)malloc(sizeof(Pacote));
    if (novo_pacote == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    novo_pacote->id = id;
    printf("Digite a cidade de origem: ");
    scanf("%s", novo_pacote->cida_ori);
    printf("Digite a cidade de destino: ");
    scanf("%s", novo_pacote->cida_dest);
    printf("Digite o conteudo do produto: ");
    scanf(" %[^\n]", novo_pacote->conteudo);
    novo_pacote->status = 1;

    novo_pacote->proximo = lista_pacotes;
    return novo_pacote;
}

void alterar_pacote(Pacote **lista_pacotes) {
    int novo_status;
    int id_temp;

    printf("Digite o ID do pacote que você deseja alterar: ");
    scanf("%d", &id_temp);
    if (id_temp < 0) {
        printf("Insira um id valido\n\n");
        return alterar_pacote(lista_pacotes);
    }

    Pacote* lista_temp = *lista_pacotes;

    while (lista_temp != NULL) {
        if (lista_temp->id == id_temp) {
            printf("Digite o novo status do pacote: ");
            scanf("%d", &lista_temp->status);
            return;
        }
        lista_temp = lista_temp->proximo;
    }
    printf("Pacote não encontrado\n");
}

void consultar_pacote(Pacote *lista_pacotes) {
    int id_temp;

    printf("Digite o ID do pacote que você deseja consultar: ");
    scanf("%d", &id_temp);
    if (id_temp < 0) {
        printf("Insira um id valido\n\n");
        return consultar_pacote(lista_pacotes);
    }

    while (lista_pacotes != NULL) {
        if (lista_pacotes->id == id_temp) {
            printf("ID: %d, Cidade Origem: %s, Cidade Destino: %s, Conteúdo: %s, Status: %d\n",
                lista_pacotes->id, lista_pacotes->cida_ori, lista_pacotes->cida_dest,lista_pacotes->conteudo, lista_pacotes->status);
            return;
        }
        lista_pacotes = lista_pacotes->proximo;
    }
    printf("Pacote não encontrado\n");
}

void excluir_pacote(Pacote **lista_pacotes) {
    int id_temp;

    printf("Digite o ID do pacote que você deseja excluir: ");
    scanf("%d", &id_temp);
    if (id_temp < 0) {
        printf("Insira um id valido\n\n");
        return excluir_pacote(lista_pacotes);
    }

    Pacote* lista_temp = *lista_pacotes;

    while (lista_temp != NULL) {
        if (lista_temp->id == id_temp) {
            lista_temp->status = 99;
            printf("Pacote excluido com sucesso!\n");
            return;
        }
        lista_temp = lista_temp->proximo;
    }
    printf("Pacote não encontrado\n");
}