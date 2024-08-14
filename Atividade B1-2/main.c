#include <stdio.h>
#include <stdlib.h>

float calcularDesconto(float* valor, int desconto);

int main() {
  char* Produtos[5] = {"Teclado", "Mouse", "Monitor", "Impressora", "Fone de Ouvido"};
  float* Precos[5];
  int valor_desconto;

  printf("Bem vindo(a) a sua loja online!\n");
  printf("Produtos disponíveis:\n");
  for (int i = 0; i < 5; i++){
    printf("%dº - %s\n", i+1, Produtos[i]);
  }

  printf("Digite o número do produto desejado: ");
  int produto;
  scanf("%d", &produto);

  printf("Digite a quantidade desejada: ");
  int quantidade;
  scanf("%d", &quantidade);


  switch(produto){
    case 1:
      Precos[0] = malloc(sizeof(float));
      printf("Valor do teclado:"); scanf("%f", Precos[0]);
      printf("Desconto: "); scanf("%d", &valor_desconto);

      printf("Preço sem Desconto: R$%.2f\n", *Precos[0] * quantidade);
      printf("Preço com Desconto: R$%.2f", calcularDesconto(*Precos, valor_desconto)*quantidade);
      break;
    case 2:
      Precos[1] = malloc(sizeof(float));
      printf("Valor do mouse:"); scanf("%f", Precos[1]);
      printf("Desconto: "); scanf("%d", &valor_desconto);

      printf("Preço sem Desconto: R$%.2f\n", *Precos[1] * quantidade);
      printf("Preço com Desconto: R$%.2f", calcularDesconto(*Precos, valor_desconto)*quantidade);
      break;
    case 3:
      Precos[2] = malloc(sizeof(float));
      printf("Valor do monitor:"); scanf("%f", Precos[2]);
      printf("Desconto: "); scanf("%d", &valor_desconto);

      printf("Preço sem Desconto: R$%.2f\n", *Precos[2] * quantidade);
      printf("Preço com Desconto: R$%.2f", calcularDesconto(*Precos, valor_desconto)*quantidade);
      break;
    case 4:
      Precos[3] = malloc(sizeof(float));
      printf("Valor da impressora:"); scanf("%f", Precos[3]);
      printf("Desconto: "); scanf("%d", &valor_desconto);

      printf("Preço sem Desconto: R$%.2f\n", *Precos[3] * quantidade);
      printf("Preço com Desconto: R$%.2f", calcularDesconto(*Precos, valor_desconto)*quantidade);
      break;
    case 5:  
      Precos[4] = malloc(sizeof(float));
      printf("Valor do fone de ouvido:"); scanf("%f", Precos[4]);
      printf("Desconto: "); scanf("%d", &valor_desconto);

      printf("Preço sem Desconto: R$%.2f\n", *Precos[4] * quantidade);
      printf("Preço com Desconto: R$%.2f", calcularDesconto(*Precos, valor_desconto)*quantidade);
      break;
    default:
      printf("Produto não encontrado");
      break;
  }
  return 0;
}

float calcularDesconto(float* valor, int desconto){
  float total = *valor - (*valor * desconto/100.0);
  return total;
}