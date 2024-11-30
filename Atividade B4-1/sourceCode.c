/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof. Veríssimo                                */
/*             Objetivo: Ordernar Array                                   */
/*                                                                        */
/* ~Pedro Coelho do Nascimento                             Data:30/11/2024*/
/*------------------------------------------------------------------------*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    int tam;
    printf("Digite o tamanho do Array: ");
    scanf("%d", &tam);
    int arr[tam];
    
    for(int i=0; i<tam; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Array original: \n");
    printArray(arr, tam);
    bubbleSort(arr, tam);
    printf("Array ordenado: \n");
    printArray(arr, tam);
    return 0;
}