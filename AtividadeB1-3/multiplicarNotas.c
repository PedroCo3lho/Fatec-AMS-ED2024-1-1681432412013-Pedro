#include <stdio.h>

//modifica o arrray sem precisar declarar outro, faz alterações direto no endereço da memória
void multiplicar_notas(int *array, int len, int mult){
  for(int i=0; i<len; i++){
    *(array+i) *= mult;
  }
}