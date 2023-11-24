#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Function to swap numbers
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* busca sequencial recursiva em vetor */
int bSeq_aux(int v[], int a, int b, int x, int *numComparacoes)
{
    if (a > b)
        return -1;

    (*numComparacoes)++;
    if (x >= v[b])
        return b;

    return bSeq_aux(v, a, b - 1, x, numComparacoes);
}

void insere(int v[], int a, int b, int *numComparacoes)
{
    int p = bSeq_aux(v, a, b - 1, v[b], numComparacoes);
    int i = b;

    while (i > p + 1)
    {
        swap(&v[i], &v[i - 1]);
        i--;
    }
    return;
}

void insSort_aux(int v[], int a, int b, int *numComparacoes)
{
    if (a >= b)
        return;

    insSort_aux(v, a, b - 1, numComparacoes);
    insere(v, a, b, numComparacoes);
    return;
}

int minimo(int vetor[], int a, int b)
{
    int menorIndex;

    if (a == b)
        return a;

    menorIndex = minimo(vetor, a, b - 1);

    if (vetor[b] < vetor[menorIndex])
        menorIndex = b;

    return menorIndex;
}

void selSort_aux(int v[], int a, int b)
{
    int minIndex;
    if (a == b)
        return;

    minIndex = minimo(v, a, b);

    swap(&v[a], &v[minIndex]);

    selSort_aux(v, a + 1, b);
}

/* Funcao auxiliar para MergeSort*/
void intercala(int vetor[], int a, int m, int b, int *numComparacoes)
{
    int u[b];
    int i = a;
    int j = m + 1;

    if (a >= b)
        return;

    for (int k = 0; k <= b - a; k++)
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

void mSort_aux(int v[], int a, int b, int *numComparacoes)
{
    if (a >= b)
        return;

    int m = floor((a + b) / 2);
    mSort_aux(v, a, m, numComparacoes);
    mSort_aux(v, m + 1, b, numComparacoes);

    intercala(v, a, m, b, numComparacoes);
}

/* Funcao auxiliar quicksort */
int partition(int v[], int a, int b)
{
    int x = v[b];
    int i = (a - 1);

    for (int j = a; j <= b - 1; j++)
    {
        if (v[j] <= x)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[b]);
    return (i + 1);
}

void quickSort(int v[], int a, int b)
{
    if (a < b)
    {
        int p = partition(v, a, b);
        quickSort(v, a, p - 1);
        quickSort(v, p + 1, b);
    }
}

// retorna o indice do pai
int pai(int i)
{
    return (i - 1) / 2;
}
// retorna o indice do filho esquerdo
int esquerda(int i)
{
    return 2 * i + 1;
}
// retorna o indice do filho direito
int direita(int i)
{
    return 2 * i + 2;
}

void maxheapify(int v[], int i, int n)
{
    int maior, esq, dir;

    esq = esquerda(i);
    dir = direita(i);

    if (esq < n && v[esq] > v[i])
        maior = esq;
    else
        maior = i;
    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i)
    {
        swap(&v[i], &v[maior]);
        maxheapify(v, maior, n);
    }
}

void buildmaxheap(int v[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(v, i, n);
}

void heapSort(int v[], int n)
{
    buildmaxheap(v, n);

    for (int i = n; i >= 1; i--)
    {
        swap(&v[0], &v[i]);
        maxheapify(v, 0, i - 1);
    }
}

void randomize(int arr[], int n)
{
    srand(time(NULL));

    for (int i = n - 1; i > 0; i--)
        swap(&arr[i], &arr[rand() % (i + 1)]);
}

void printArr(int v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", v[i]);

    printf("\n");
}

void print_ten_first_last(int v[], int n)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", v[i]);

    for (int i = n - 1; i > n - 10; i--)
        printf("%d ", v[i]);

    printf("\n");

    return;
}

int main()
{
    clock_t start, end;
    double seconds;
    int n = 1000*100;
    int numComparacoes = 0;

    int *v1 = (int *)malloc(n * sizeof(int));
    int *v2 = (int *)malloc(n * sizeof(int));
    int *v3 = (int *)malloc(n * sizeof(int));
    int *v4 = (int *)malloc(n * sizeof(int));
    int *v5 = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        v1[i] = i;

    randomize(v1, n);
    memcpy(v2, v1, n * sizeof(int));
    memcpy(v3, v1, n * sizeof(int));
    memcpy(v4, v1, n * sizeof(int));
    memcpy(v5, v1, n * sizeof(int));

    // insertionsort
    start = clock();
    insSort_aux(v1, 0, n - 1, &numComparacoes);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%8f segundos foi o tempo de execução do algoritmo InsertionSort\n", seconds);

    // selectionsort
    start = clock();
    selSort_aux(v2, 0, n - 1);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%8f segundos foi o tempo de execução do algoritmo SelectionSort\n", seconds);

    // mergesort
    start = clock();
    mSort_aux(v3, 0, n - 1, &numComparacoes);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%8f segundos foi o tempo de execução do algoritmo MergeSort\n", seconds);

    // quicksort
    start = clock();
    quickSort(v4, 0, n - 1);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%8f segundos foi o tempo de execução do algoritmo Quicksort\n", seconds);

    // heapsort
    start = clock();
    heapSort(v5, n - 1);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%8f segundos foi o tempo de execução do algoritmo HeapSort\n", seconds);

    printf("\nPrimeiros e ultimos 10 indices de cada vetor\n");

    print_ten_first_last(v1, n);
    print_ten_first_last(v2, n);
    print_ten_first_last(v3, n);
    print_ten_first_last(v4, n);
    print_ten_first_last(v5, n);

    free(v1);
    free(v2);
    free(v3);
    free(v4);
    free(v5);
}