# EM PORTUGUÊS

## TRABALHO 1 - ORDENAÇÃO
Resumo:
Primeiro trabalho avaliativo para a disciplina CI1056 - Algoritmos e Estrutura de Dados II, do curso de Ciência da Computação da Universidade Federal do Paraná.

### 1. Descrição

O objetivo do trabalho é implementar as versões recursivas dos seguintes algoritmos utilizando a linguagem C: Busca Sequencial, Busca Binária, Insertion Sort, Selection Sort, Merge Sort, Quick Sort e Heap Sort.
Junto com a implementação, deve ser entregue um relatório em PDF com experimentos relatando:
- Quantidade de comparações feitas entre elementos do vetor;
- Tempo de execução em segundos físicos.

A definição dos testes a serem feitos e discutidos no relatório fica a cargo do aluno.

### 2. Template

A implementação deve usar o template fornecido pelo professor.
O arquivo ordenacao.h contém os protótipos (assinaturas) das funções que obrigatoriamente devem ser implementadas, no arquivo ordenacao.c.
Não é permitida mudança nos protótipos de funções disponibilizados no arquivo ordenacao.h. É permitida a criação de funções auxiliares se necessário. Também é permitida a criação de arquivos de header (.h) e de implementação (.c) complementares, se necessário.
É obrigatória a inclusão de um arquivo main.c com alguns testes nos algoritmos implementados.
A definição dos testes fica a cargo do aluno.
O arquivo deve compilar sem erros ou avisos através do comando make.
O nome do binário deve ser trab. Ajuste isso no makefile. O binário deve executar em sistemas Linux executando o programa sem a passagem de nenhum parâmetro (e.g., ./trab).

### 3. Arquivos a serem entregues

Devem ser entregues:

- Arquivos de código fonte .c e .h do programa;

- makefile;

- relatório.pdf
  
### 4. Relatório

Realize testes e discorra sobre esses testes no relatório. Relacione, por exemplo, o tempo de execução em seu computador para diferentes algoritmos e também o número de comparações realizadas pelos algoritmos para diferentes tamanhos de entradas.
Você pode incluir gráficos ou tabelas no relatório para torná-lo mais informativo e interessante. O relatório deve ter no máximo duas páginas se utilizado espaçamento simples e coluna dupla, ou no máximo três páginas para espaçamento 1,5 ou duplo e formato de uma coluna.

### 5. Dicas
#### 5.1 Contando o tempo
Para contar o tempo gasto por determinada função em C, inclua a biblioteca time.h. Veja a
seguir um exemplo para contar o tempo em segundos necessário para se executar uma função.

```
#include <time.h>
//...
clock_t start, end; //variáveis do tipo clock_t
double total;
start = clock(); //start recebe o "ciclo" corrente
minhaFuncao(); //chama a função que desejamos medir o tempo
end = clock(); //end recebe o "ciclo" corrente
//o tempo total é a diferença dividida pelos ciclos por segundo
total = ((double)end - start) / CLOCKS_PER_SEC;
//total agora possui o tempo em segundos
printf("Tempo total: %f", total);
```

#### 5.2 Função clock
A especificação em C da função clock() é clara em dizer que a função deve retornar o tempo de CPU (CPU time), mas algumas fontes citam que o Windows ignora a especificação e conta o tempo de parede (Wall clock time). Para simplificar, será aceito tanto o CPU time quanto o Wall Clock time, mas deixe claro em seu relatório qual sistema operacional você usou. 
Para tornar os testes mais confiáveis, execute os programas com "tudo fechado" em sua máquina. Por exemplo, não abra o navegador web enquanto executar os testes, já que o navegador pode competir por recursos e gerar diferenças nos tempos, especialmente para o wall clock time.

# IN ENGLISH:

## PROJECT 1 - SORTING
Summary:
First evaluation project for the CI1056 - Algorithms and Data Structures II course, part of the Computer Science program at the Federal University of Paraná.

### 1. Description

The objective of this assignment is to implement the recursive versions of the following algorithms using the C language: Sequential Search, Binary Search, Insertion Sort, Selection Sort, Merge Sort, Quick Sort, and Heap Sort.
Along with the implementation, a PDF report must be submitted with experiments reporting:
- Quantity of comparisons made between vector elements;
- Execution time in physical seconds.

The definition of the tests to be performed and discussed in the report is up to the student.

### 2. Template

The implementation should use the template provided by the professor.
The file "ordenacao.h" contains the prototypes (signatures) of the functions that must be implemented in the file "ordenacao.c".
Changing the function prototypes provided in the "ordenacao.h" file is not allowed. The creation of auxiliary functions is allowed if necessary. The creation of complementary header (.h) and implementation (.c) files is also allowed if necessary.
It is mandatory to include a "main.c" file with some tests on the implemented algorithms.
The definition of the tests is up to the student.
The file must compile without errors or warnings through the "make" command.
The name of the binary file must be "trab". Adjust it in the makefile. The binary file must run on Linux systems by running the program without passing any parameters (e.g., ./trab).

### 3. Files to be submitted

The following files must be submitted:

- Program source code files (.c and .h);

- Makefile;

- Report.pdf
  
### 4. Report

Perform tests and discuss them in the report. For example, relate the execution time on your computer for different algorithms and also the number of comparisons made by the algorithms for different input sizes.
You can include graphics or tables in the report to make it more informative and interesting. The report must be a maximum of two pages if using single spacing and double column, or a maximum of three pages for 1.5 or double spacing and single column format.

### 5. Tips
#### 5.1 Counting time
To count the time spent by a specific function in C, include the time.h library. See the following example to count the time in seconds required to execute a function.

```
#include <time.h>
//...
clock_t start, end; //variáveis do tipo clock_t
double total;
start = clock(); //start recebe o "ciclo" corrente
minhaFuncao(); //chama a função que desejamos medir o tempo
end = clock(); //end recebe o "ciclo" corrente
//o tempo total é a diferença dividida pelos ciclos por segundo
total = ((double)end - start) / CLOCKS_PER_SEC;
//total agora possui o tempo em segundos
printf("Tempo total: %f", total);
```


#### 5.2 clock function
The C specification for the clock() function is clear in saying that the function should return CPU time, but some sources mention that Windows ignores the specification and counts wall clock time. To simplify, both CPU time and Wall Clock time will be accepted, but make it clear in your report which operating system you used. 
To make the tests more reliable, run the programs with "everything closed" on your machine. For example, don't open the web browser while running the tests, as the browser may compete for resources and generate differences in times, especially for wall clock time.



