#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap numbers
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function is same in both iterative and recursive*/
int partition(int v[], int a, int b)
{
    int x = v[b];
    int i = (a - 1);
 
    for (int j = a ; j <= b-1 ; j++) {
        if (v[j] <= x) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[b]);
    return (i + 1);
}
 
void quickSort(int v[], int a, int b)
{
    if (a < b) {
        int p = partition(v, a, b);
        quickSort(v, a, p - 1);
        quickSort(v, p + 1, b);
    }
}

void quickSortIterative(int v[], int l, int h) {
    //int stack[h - l + 1];
    int *stack = (int*)malloc((h-l+1) * sizeof(int));
	
	int top = -1;
 
    stack[++top] = l;
    stack[++top] = h;
 
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
 
        int p = partition(v, l, h);
 
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        } 
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}


void randomize ( int arr[], int n ) {
    srand ( time(NULL) );
     
    for (int i = n-1; i > 0; i--)
        swap(&arr[i], &arr[rand() % (i+1)]);    
}

// A utility function to print contents of v
void printArr(int v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
       printf("%d ", v[i]);
	
	printf("\n");	
}

// Driver code
int main()
{
	int n = 1000*1000*80;
	int *v1 = (int*)malloc(n * sizeof(int));
	int *v2 = (int*)malloc(n * sizeof(int));
	
	
	clock_t start, end;
    double seconds;
	
	
	for (int i=0; i<n; i++) v1[i] = i;
	
	randomize(v1,n);
	
	//printArr(v1, n);
	
	for (int i=0; i<n; i++) v2[i] = v1[i];
	
	//quicksort recursivo
	
	start = clock();
	quickSort(v1, 0, n - 1); 
	end = clock();
	seconds = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Quicksort recursivo executou em %f segundos\n", seconds);
    
	//quicksort iterativo
	
	start = clock();
	quickSortIterative(v2, 0, n - 1);
	end = clock();
	seconds = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Quicksort iterativo executou em %f segundos\n", seconds);
	
	//getchar();
	free(v1);
	free(v2);
	
}