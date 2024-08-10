/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof. Veríssimo                                 */
/*             Objetivo: Cálculo tempo execuçao-Insertion Sort            */
/*                                                                        */
/* ~Pedro Coelho do Nascimento                             Data:10/08/2024*/
/*------------------------------------------------------------------------*/
#include <stdio.h>
#include <time.h>

// Função para contar o tempo de execução de cada instrução
double calcTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void insertionSort(int A[], int n) {
    clock_t startTotal, endTotal;
    startTotal = clock(); // Início da medição de tempo total

    for (int j = 0; j < n; j++) {  // Lembrar que em C, os índices começam em 0
        clock_t start, end;
        double t;

        start = clock();
        int key = A[j];
        end = clock();
        t = calcTime(start, end);
        printf("Tempo para atribuição de key: %f segundos\n", t);

        start = clock();
        int i = j - 1;
        end = clock();
        t = calcTime(start, end);
        printf("Tempo para atribuição de i: %f segundos\n", t);

        start = clock();
        while (i >= 0 && A[i] > key) {
            end = clock();
            t = calcTime(start, end);
            printf("Tempo para comparação no while: %f segundos\n", t);

            start = clock();
            A[i + 1] = A[i];
            i = i - 1;
            end = clock();
            t = calcTime(start, end);
            printf("Tempo para atribuição e decremento: %f segundos\n", t);

            start = clock(); // reinicia o relógio para próxima comparação
        }
        end = clock();
        t = calcTime(start, end);
        printf("Tempo total dentro do loop while para j=%d: %f segundos\n", j, t);

        start = clock();
        A[i + 1] = key;
        end = clock();
        t = calcTime(start, end);
        printf("Tempo para atribuição final: %f segundos\n", t);
        printf("---------------------------------------------------------------\n");
    }

    endTotal = clock(); // Fim da medição de tempo total
    double totalTimeSpent = calcTime(startTotal, endTotal);
    printf("Tempo total de execução do insertionSort: %f segundos\n", totalTimeSpent);
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

int main() {
    int A[] = {25, 20, 15, 10, 5, 0, -5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original:\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("Array ordenado:\n");
    printArray(A, n);

    return 0;
}