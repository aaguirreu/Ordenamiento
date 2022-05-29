#include <stdio.h>
#include <time.h>

/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Exercício de Programação 3 do capítulo 2 do livro Conceitos de Linguagens de Programação - Nona Edição de Robert Sebesta
*   QuickSort Recursivo e Iterativo
*   QuickSort Recursive and Iterative 
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int l, int h){
    int j, x = arr[h];
    int i = (l - 1);

    for (j = l; j <= h- 1; j++){
        if (arr[j] <= x){
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSortIterative (int arr[], int l, int h){
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 ){
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l ){
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h ){
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}
 

void quicksort (int a[], int n) {
    clock_t start_t, end_t;
    double total_t;
    
    start_t = clock();

    quickSortIterative(a, 0, n);

    end_t = clock();
    total_t = 1000.0*(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tiempo CPU: %.2Lf ms\n", total_t);
}