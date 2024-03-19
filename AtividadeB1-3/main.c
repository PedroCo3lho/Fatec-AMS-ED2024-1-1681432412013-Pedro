/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Manipulação de Array de Inteiros com Ponteiros   */
/*             Paradigama: - programação modular                          */
/*                                                                        */
/* ~Pedro Coelho do Nascimento                             Data:18/03/2024*/
/*------------------------------------------------------------------------*/

#include <stdio.h>

int maior_numero(int *array, int len);
int soma_elementos(int *array, int len);
void multiplicar_elementos(int *array, int len, int mult);
void print_array(int *arr, int len);

void ordenar_notas(int *array, int len){
  int temp;
  for(int i=0; i<len-1; i++){
    for(int j=i+1; j<len; j++){
      if(*(array+i) > *(array+j)){
        temp = *(array+i);
        *(array+i) = *(array+j);
        *(array+j) = temp;
      }
    }
  }
}

int main(){
  int TAMANHO = 5;
  int array[TAMANHO];
  
  printf("Digite 5 Notas:\n");
  for(int i = 0; i < TAMANHO; i++){
    printf("%dª nota: ", i + 1);
    scanf("%d", &array[i]);
  }

  printf("\nNotas Digitadas: "); print_array(array, TAMANHO);

  ordenar_notas(array, TAMANHO);
  printf("Notas Ordenadas: ");print_array(array, TAMANHO);

  printf("Maior Nota: %d\n", maior_nota(array, TAMANHO));

  printf("Soma das Notas: %d\n\n", soma_notas(array, TAMANHO));

  int multiplicador;
  printf("Multiplicar cada nota por: ");scanf("%d", &multiplicador);

  multiplicar_notas(array, TAMANHO, multiplicador);//chama a função para multiplicar os elementos do array
  printf("Notas multiplicadas por %d: ", multiplicador);
  print_array(array, TAMANHO);//imprime as notas multiplicado

  return 0;
}