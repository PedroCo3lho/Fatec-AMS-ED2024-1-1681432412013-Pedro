# InsertionSortExecTime

### A cada instrução feita no metodo `insertionSort()` é calculado o tempo de execução utilizando a biblioteca Time do C em que nos valemos dos seguintes tipos de dados e funções:
  - `clock_t` é um tipo de dado definido na biblioteca <time.h> para representar valores de tempo de CPU
  - `CLOCKS_PER_SEC` representa o número de ticks do clock de CPU por segundo. Isso é usado para converter o valor de ticks do tipo clock_t (obtido de clock()) em segundos.
  - `clock()` retorna o número de ticks de clock de CPU consumidos desde que o programa começou a ser executado. O tipo de retorno da função é `clock_t`