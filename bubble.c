#include <stdio.h>
#include <time.h>

void bubble_sort (int *a, int n) {
    int i, t, j = n, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = 1;
            }
        }
        j--;
    }
}
 
void bubble (int a[], int n) {
    clock_t start_t, end_t;
    double total_t;
    
    start_t = clock();

    bubble_sort(a, n);

    end_t = clock();
    total_t = 1000.0*(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tiempo CPU: %.2Lf ms\n", total_t);
}