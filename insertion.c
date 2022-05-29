#include <stdio.h>
#include <time.h>
 
void insertion_sort(int *a, const size_t n) {
	for(size_t i = 1; i < n; ++i) {
		int key = a[i];
		size_t j = i;
		while( (j > 0) && (key < a[j - 1]) ) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = key;
	}
}
 
void insertion(int a[], int n) {
	clock_t start_t, end_t;
    double total_t;
    
    start_t = clock();

    insertion_sort(a, n);

    end_t = clock();
    total_t = 1000.0*(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tiempo CPU: %.2Lf ms\n", total_t);
}