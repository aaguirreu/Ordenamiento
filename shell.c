#include <stdio.h>
#include <time.h>
 
void shell_sort (int *a, int n) {
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
}
 
void shell (int a[], int n) {
    clock_t start_t, end_t;
    double total_t;
    
    start_t = clock();

    shell_sort(a, n);

    end_t = clock();
    total_t = 1000.0*(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tiempo CPU: %.2Lf ms\n", total_t);
}