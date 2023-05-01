#include "ordenacao.h"

#include <string.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Kauan da Rosa Paulino", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return ;
}

int bSeq_aux(int vetor[], int a, int b, int x, int* numComparacoes) {
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
	return bSeq_aux(vetor, 0, tam-1, valor, numComparacoes);
}

int bBin_aux(int vetor[], int a, int b, int x, int* numComparacoes) {
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
	return bBin_aux(vetor, 0, tam-1, valor, numComparacoes);
}

void insere(int v[], int a, int b) {
    int ultimo = v[b-1];
    int j = b-2;

    while (j >= 0 && v[j] > ultimo) {
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
	int numComparacoes;
	insSort_aux(vetor, 0, tam-1, &numComparacoes);
	return numComparacoes;
}

int selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}
