#include <stdio.h>
#include <time.h>
 
void selection_sort (int *a, int n) {
    int i, j, m, t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}
 
void selection (int a[], int n) {
    clock_t start_t, end_t;
    double total_t;
    
    start_t = clock();

    selection_sort(a, n);

    end_t = clock();
    total_t = 1000.0*(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tiempo CPU: %.2Lf ms\n", total_t);
}
 