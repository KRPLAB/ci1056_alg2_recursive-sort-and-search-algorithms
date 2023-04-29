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


int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	*numComparacoes = 99;
	return -1;
}

int insertionSort(int vetor[], int tam){	
	vetor[0] = 99;
	return -1;
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
