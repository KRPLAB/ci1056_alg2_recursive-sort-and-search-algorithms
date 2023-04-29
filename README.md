# TRABALHO 1 - ORDENAÇÃO
Resumo:
Primeiro trabalho avaliativo para a disciplina CI1056 - Algoritmos e Estrutura de Dados II, do curso de Ciência da Computação da Universidade Federal do Paraná.

## 1. Descrição

O objetivo do trabalho é implementar as versões recursivas dos seguintes algoritmos utilizando a linguagem C: Busca Sequencial, Busca Binária, Insertion Sort, Selection Sort, Merge Sort, Quick Sort e Heap Sort.
Junto com a implementação, deve ser entregue um relatório em PDF com experimentos relatando:
  a. Quantidade de comparações feitas entre elementos do vetor;
  b. Tempo de execução em segundos físicos.

A definição dos testes a serem feitos e discutidos no relatório fica a cargo do aluno.

## 2. Template

A implementação deve usar o template fornecido pelo professor.
O arquivo ordenacao.h contém os protótipos (assinaturas) das funções que obrigatoriamente devem ser implementadas, no arquivo ordenacao.c.
Não é permitida mudança nos protótipos de funções disponibilizados no arquivo ordenacao.h. É permitida a criação de funções auxiliares se necessário. Também é permitida a criação de arquivos de header (.h) e de implementação (.c) complementares, se necessário.
É obrigatória a inclusão de um arquivo main.c com alguns testes nos algoritmos implementados.
A definição dos testes fica a cargo do aluno.
O arquivo deve compilar sem erros ou avisos através do comando make.
O nome do binário deve ser trab. Ajuste isso no makefile. O binário deve executar em sistemas Linux executando o programa sem a passagem de nenhum parâmetro (e.g., ./trab).

## 3. Arquivos a serem entregues

Devem ser entregues:

- Arquivos de código fonte .c e .h do programa;

- makefile;

- relatório.pdf
  
## 4. Relatório

Realize testes e discorra sobre esses testes no relatório. Relacione, por exemplo, o tempo de execução em seu computador para diferentes algoritmos e também o número de comparações
realizadas pelos algoritmos para diferentes tamanhos de entradas.
Você pode incluir gráficos ou tabelas no relatório para torná-lo mais informativo e interessante.
O relatório deve ter no máximo duas páginas se utilizado espaçamento simples e coluna dupla,
ou no máximo três páginas para espaçamento 1,5 ou duplo e formato de uma coluna.

## 5. Dicas
### 5.1 Contando o tempo
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

### 5.2 Função clock
A especificação em C da função clock() é clara em dizer que a função deve retornar o tempo
de CPU (CPU time), mas algumas fontes citam que o Windows ignora a especificação e conta
o tempo de parede (Wall clock time). Para simplificar, será aceito tanto o CPU time quanto
o Wall Clock time, mas deixe claro em seu relatório qual sistema operacional você usou.
Para tornar os testes mais confiáveis, execute os programas com "tudo fechado" em sua máquina.
Por exemplo, não abra o navegador web enquanto executar os testes, já que o navegador pode
competir por recursos e gerar diferenças nos tempos, especialmente para o wall clock time.

