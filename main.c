#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenacao.h"

void preenche(int v[], int n){
	// Preenche o vetor com numeros aleatorios
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100000000;
}	

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;
	int valor;
	
	int n = 1000*1000*80;
	int *v1 = (int*)malloc(n * sizeof(int));
	int *v2 = (int*)malloc(n * sizeof(int));
	int *v3 = (int*)malloc(n * sizeof(int));
	int *v4 = (int*)malloc(n * sizeof(int));
	int *v5 = (int*)malloc(n * sizeof(int));

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	
	preenche(v1,n);
	memcpy(v2, v1, n * sizeof(int));
	memcpy(v3, v1, n * sizeof(int));
	memcpy(v4, v1, n * sizeof(int));
	memcpy(v5, v1, n * sizeof(int));

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;
    double total;
	
	//insertionSort
	start = clock();
	numComp = insertionSort(v2, n);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total insertionSort: %f", total);

	//selectionSort
	start = clock();
	numComp = selectionSort(v1, n);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTempo total selectionSort: %f", total);
	
	//mergeSort
	start = clock();
	numComp = mergeSort(v3, n);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTempo total mergeSort: %f", total);
	
	//quickSort
	start = clock();
	numComp = quickSort(v4, n);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTempo total quickSort: %f", total);
	
	/*numComp = heapSort(v5, n);*/

	/*for(int i=0; i < 3; i++){
		printf("%d ", vetor[i]);
	}*/
	
	srand(time(NULL));
	valor = rand() % 100000000;
	
	//buscaSequencial
	start = clock();
	idxBusca = buscaSequencial(v1, n, valor, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nValor encontrado no indice (caso seja -1, não foi encontrado): %d\nNumero de comparacoes foi: %d", idxBusca, numComp);
	
	start = clock();
	idxBusca = buscaBinaria(v1, n, valor, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nValor encontrado no indice (caso seja -1, não foi encontrado): %d\nNumero de comparacoes foi: %d", idxBusca, numComp);
	printf("\n");

	//É obrigatório que você libere a memória alocada dinamicamente via free
	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(v5);

	return 0;
}
