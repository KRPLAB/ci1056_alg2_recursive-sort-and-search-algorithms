#include "ordenacao.h"
#include <math.h>
#include <string.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Kauan da Rosa Paulino", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20182697;
}

int bSeq_aux(int vetor[], int a, int b, int x, int* numComparacoes){
    if (a > b)
        return -1;
    if (vetor[b] == x) 
	{
		(*numComparacoes)++;
		return b;
	}
	(*numComparacoes)++;
    return bSeq_aux(vetor, a, b - 1, x, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	*numComparacoes = 0;
	return bSeq_aux(vetor, 0, tam-1, valor, numComparacoes);
}

int bBin_aux(int vetor[], int a, int b, int x, int* numComparacoes){
    if (b >= a) 
	{
        int m = a + (b - a) / 2;
        if (vetor[m] == x)
            return m;
		
        if (vetor[m] > x)
            return bBin_aux(vetor, a, m-1, x, numComparacoes);
		
        return bBin_aux(vetor, m+1, b, x, numComparacoes);
    }
    return -1;
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	*numComparacoes = 0;
	return bBin_aux(vetor, 0, tam-1, valor, numComparacoes);
}

void insere(int v[], int a, int b){
    int p = buscaSequencial();
    int j = b-1;

    while (j >= a && v[j] > ultimo) {
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = ultimo;
    return;

}

void insSort_aux(int vetor[], int a, int b, int* numComparacoes){
	if (a >= b)
		return;
	
	(*numComparacoes)++;
    insSort_aux(vetor, a, b-1, numComparacoes);
    insere(vetor, a, b);
    return;
}

int insertionSort(int vetor[], int tam){	
	int numComparacoes = 0;
	insSort_aux(vetor, 0, tam-1, &numComparacoes);
	return numComparacoes;
}

// Funcao para trocar dois elementos do vetor
void troca(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

// Funcao para encontrar o indice do menor elemento do vetor
int minimo(int vetor[], int a, int b, int *numComparacoes){
	int menorIndex;
	
	if(a == b)
		return a;
	
	(*numComparacoes)++;
	menorIndex = minimo(vetor, a, b-1, numComparacoes);
	
	if (vetor[b] < vetor[menorIndex])
		menorIndex = b;
		
	return menorIndex;
}

// Funcao para ordenar o vetor usando o algoritmo selection sort
void selSort_aux(int vetor[], int a, int b, int *numComparacoes){	
	if(a == b)
		return;
		
	troca(&vetor[a], &vetor[minimo(vetor, a, b, numComparacoes)]);
	return selSort_aux(vetor, a + 1, b, numComparacoes);
}

int selectionSort(int vetor[], int tam){
    int numComparacoes = 0;
	
    selSort_aux(vetor, 0, tam, &numComparacoes);
    
    return numComparacoes;
}

void intercala(int vetor[], int a, int m, int b, int *numComparacoes){
	int u[b];
	int i = a;
	int j = m + 1;

	if (a >= b)
		return;
	
    for (int k = 0; k <= b-a; k++)
	{
		(*numComparacoes)++;
		if ((j > b) || (i <= m && vetor[i] <= vetor[j]))
		{
			u[k] = vetor[i];
			i++;
		}
		else
		{
			u[k] = vetor[j];
			j++;
		}
	}
	memcpy(vetor + a, u, (b - a + 1) * sizeof(int));
	return;
}

void mSort_aux(int vetor[], int a, int b, int *numComparacoes){
    if (a >= b)
		return;
		
	int m = floor((a+b)/2);
	mSort_aux(vetor, a, m, numComparacoes);
	mSort_aux(vetor, m+1, b, numComparacoes);
	
	return intercala(vetor, a, m, b, numComparacoes);
}

int mergeSort(int vetor[], int tam){
    int numComparacoes = 0;
	
    mSort_aux(vetor, 0, tam, &numComparacoes);
    
    return numComparacoes;
}

int particiona(int vetor[], int a, int b, int *numComparacoes){
    int x = vetor[b];
    int i = (a - 1);
 
    for (int j = a ; j <= b-1 ; j++)
	{
		(*numComparacoes)++;
        if (vetor[j] <= x)
		{
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[b]);
    return (i + 1);
}
 
void qSort_aux(int vetor[], int a, int b, int *numComparacoes){
    if (a > b)
		return;
		
	int p = particiona(vetor, a, b, numComparacoes);
	qSort_aux(vetor, a, p - 1, numComparacoes);
	qSort_aux(vetor, p + 1, b, numComparacoes);
}

int quickSort(int vetor[], int tam){
	int numComparacoes = 0;
	
	qSort_aux(vetor, 0, tam, &numComparacoes);
	
	return numComparacoes;
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}
