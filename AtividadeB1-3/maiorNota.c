#include <stdio.h>

//percorre pelo array compara os elementos e retorna o maior
int maior_nota(int *array, int len){
  int maior = *array;//aramazenar o primeiro elemento do array
  for(int i=1; i<len; i++){
    if(*(array+i) > maior){
      maior = *(array+i);
    }
  }
  return maior;
}
