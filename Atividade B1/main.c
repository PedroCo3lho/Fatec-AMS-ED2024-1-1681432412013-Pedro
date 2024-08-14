#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int numerosInteiros[5];
  int i, j, temp;

  for(i=0; i<5; i++){
    printf("Digite o %dº número: ", i+1);
    scanf("%d", &numerosInteiros[i]);
  }

  for(i=0; i<4; i++){
    for(j=i+1; j<5; j++){
      if(numerosInteiros[i] > numerosInteiros[j]){
        temp = numerosInteiros[i];
        numerosInteiros[i] = numerosInteiros[j];
        numerosInteiros[j] = temp;
      }
    }
  }

  printf("Números em ordem crescente: ");

  for(i=0; i<5; i++){
    printf("%d ", numerosInteiros[i]);
  }
  
  return 0;
}