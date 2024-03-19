#include <stdio.h>

//percorre pelo array e soma os elementos
int soma_notas(int *array, int len){
  int soma = 0;
  for(int i=0; i<len; i++){
    soma += *(array+i);
  }
  return soma;
}