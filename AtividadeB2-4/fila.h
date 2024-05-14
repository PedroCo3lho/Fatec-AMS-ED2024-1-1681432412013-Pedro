#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILA 500

typedef struct {
  char nome[50];
  int idade;
  char motivo[100];
  int prioridade; // 1 - Normal, 2 - Prioritário, 3 - Urgente
} Paciente;

typedef struct {
  Paciente pacientes[MAXFILA];
  int inicio;
  int fim;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila *fila) {
  fila->inicio = 0;
  fila->fim = -1;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) { return (fila->fim < fila->inicio); }

// Função para adicionar um paciente à fila
void adicionarPaciente(Fila *fila, Paciente paciente) {
  if (fila->fim < MAXFILA - 1) {
    fila->fim++;
    fila->pacientes[fila->fim] = paciente;
  } else {
    printf("Fila cheia!\n");
  }
}

// Função para remover um paciente da fila
void removerPaciente(Fila *fila) {
  if (!filaVazia(fila)) {
    for (int i = fila->inicio; i < fila->fim; i++) {
      fila->pacientes[i] = fila->pacientes[i + 1];
    }
    fila->fim--;
  }
}

// Função para exibir a fila e remover pacientes da fila
void atenderPacientes(Fila *filaNormal, Fila *filaPrioritaria, Fila *filaUrgente, int n) {
  int count = 0;

  while (!filaVazia(filaUrgente)) {
    printf("Prioridade URGENTE: %s\n",
           filaUrgente->pacientes[filaUrgente->inicio].nome);
    removerPaciente(filaUrgente);
  }

  while (count < n && !filaVazia(filaNormal)) {
    printf("Atendimento NORMAL: %s\n",
           filaNormal->pacientes[filaNormal->inicio].nome);
    removerPaciente(filaNormal);
    count++;
  }

  if (count < n) {
    while (count < n && !filaVazia(filaPrioritaria)) {
      printf("Atendimento PRIORITÁRIO: %s\n",
             filaPrioritaria->pacientes[filaPrioritaria->inicio].nome);
      removerPaciente(filaPrioritaria);
      count++;
    }
  }
}

// Função para exibir pacientes em espera
void mostrarFila(Fila *fila) {
  for (int i = fila->inicio; i <= fila->fim; i++) {
    char prioridade[15];
    switch (fila->pacientes[i].prioridade) {
    case 1:
      strcpy(prioridade, "Normal");
      break;
    case 2:
      strcpy(prioridade, "Prioritário");
      break;
    case 3:
      strcpy(prioridade, "Urgente");
      break;
    }
    printf("- Nome: %s | Idade: %d | Motivo: %s | Prioridade: %s\n",
           fila->pacientes[i].nome, fila->pacientes[i].idade,
           fila->pacientes[i].motivo, prioridade);
  }
  printf("\n");
}

// Função para cadastrar um novo paciente
void cadastrarPaciente(Fila *filaNormal, Fila *filaPrioritaria, Fila *filaUrgente) {
  Paciente novoPaciente;
  int prioridade;

  printf("Nome do paciente: ");
  scanf("%s", novoPaciente.nome);
  printf("Idade do paciente: ");
  scanf("%d", &novoPaciente.idade);
  printf("Motivo da consulta: ");
  scanf(" %[^\n]",
        novoPaciente.motivo);
  printf("Prioridade (1 - Normal, 2 - Prioritário, 3 - Urgente): ");
  scanf("%d", &prioridade);

  novoPaciente.prioridade = prioridade;

  switch (prioridade) {
  case 1:
    adicionarPaciente(filaNormal, novoPaciente);
    break;
  case 2:
    adicionarPaciente(filaPrioritaria, novoPaciente);
    break;
  case 3:
    adicionarPaciente(filaUrgente, novoPaciente);
    break;
  default:
    printf("Prioridade inválida!\n");
    break;
  }
}