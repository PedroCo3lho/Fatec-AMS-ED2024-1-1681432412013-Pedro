/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof. Veríssimo                                 */
/*             Objetivo: Implemementar fila de atendimento - Hospital     */
/*             Paradigama: Implementar utilizando paradigma de fila       */
/*                                                                        */
/* ~Pedro Coelho do Nascimento                             Data:13/05/2024*/
/*------------------------------------------------------------------------*/

#include "fila.h"
#include "menu.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função principal
int main() {
  Fila filaNormal, filaPrioritaria, filaUrgente;
  inicializarFila(&filaNormal);
  inicializarFila(&filaPrioritaria);
  inicializarFila(&filaUrgente);
  int escolha;
  int numAtendimentos;

  do {
    escolha = painel();

    switch (escolha) {
    case 1:// Novo Paciente
      cadastrarPaciente(&filaNormal, &filaPrioritaria, &filaUrgente);
      break;
    case 2:// Atender Paciente
      printf("Número de pacientes em espera: "); scanf("%d", &numAtendimentos);
      atenderPacientes(&filaNormal, &filaPrioritaria, &filaUrgente, numAtendimentos);
      break;
    case 3:// Exibir Fila
      printf("\n------------------------------------------------\n");
      printf("Filas de atendimento:\n");
      printf("Normal:\n");
      mostrarFila(&filaNormal);
      printf("Prioritária:\n");
      mostrarFila(&filaPrioritaria);
      printf("Urgente:\n");
      mostrarFila(&filaUrgente);
      break;
    }
  } while (escolha != 0);

  printf("Programa encerrado!\n");
  exit(0);

  return 0;
}
