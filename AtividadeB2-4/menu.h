#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int painel(){
  printf("------------------------------------------------");
  printf("\n\nHospital do Programador! Almost there (˘･_･˘)\n");
  printf("1 - Novo Paciente\n");
  printf("2 - Atender Paciente\n");
  printf("3 - Exibir Fila\n");
  printf("0 - Sair\n");
  int escolha;
  printf("Escolha: ");  scanf("%d", &escolha);
  return escolha;
};