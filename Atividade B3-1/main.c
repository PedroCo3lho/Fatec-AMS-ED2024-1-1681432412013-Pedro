/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof. Veríssimo                                 */
/*             Objetivo: Cálculo tempo execuçao-Insertion Sort            */
/*                                                                        */
/* ~Pedro Coelho do Nascimento                             Data:10/08/2024*/
/*------------------------------------------------------------------------*/
#include <stdio.h>

// 1t
int *insertion_sort(int a[], int n) { 
  // 3t(n)
  for(int j = 1; j < n; j++) {
    // 2t(n)
    int key = a[j];
    // 2t(n)
    int i = j - 1;
    // 4t(n²)
    while(i >= 0 && a[i] > key) {
      // 4t(n²)
      a[i + 1] = a[i];
      // 1t(n²)
      i -= 1;
    }
    // 3t(n)
    a[i + 1] = key;
  }
  // 1t
  return a;                          
}

void print_array(int a[], int n) {
  for(int i = 0; i < n; i++) {
      printf("%d ", a[i]);
  }
}

int main(void) {
  int a[] = {25, 10, 15, 20, -5};
  print_array(insertion_sort(a, 5), 5);
}