#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "shell.h"
#include "quicksort.h"

int main (void)
{
    int N[20] = {100, 1000, 5000, 10000, 50000,
                100000, 200000, 400000, 600000, 800000,
                1000000, 2000000, 3000000, 4000000, 5000000,
                6000000, 7000000, 8000000, 9000000, 10000000};

    //lee el archivo 
    FILE *fp;
    static int arr[10000000];
    fp = fopen("./inputs/10000000.txt", "r");
    int num;
    int cta = 0;
    while (fscanf(fp, "%d", &num) != EOF){
        arr[cta] = num;
        //printf("%ld: %ld\n",cta, num);
        cta++;
    }
    fclose(fp);

    int n;

    //Bubble
    printf("Burbuja\n");
    for (int i = 0; i < 19; i++) {   
        n = N[i];       
        printf("Tiempo con %d numeros \n", n);

        time_t begin = time(NULL);

        //llama a las funciones de ordenamiento con n numeros a ordenar
        bubble(arr, n);

        time_t end = time(NULL);
        // calculate elapsed time by finding difference (end - begin)
        printf("Tiempo real: %d segundos\n\n", (end - begin));
    }
    printf("\n\n\n");

    // //Selection
    // printf("Selección\n");
    // for (int i = 0; i < 19; i++) {   
    //     n = N[i];       
    //     printf("Tiempo con %d numeros \n", n);

    //     time_t begin = time(NULL);

    //     //llama a las funciones de ordenamiento con n numeros a ordenar
    //     selection(arr, n);

    //     time_t end = time(NULL);
    //     // calculate elapsed time by finding difference (end - begin)
    //     printf("Tiempo real: %d segundos\n\n", (end - begin));
    // }
    // printf("\n\n\n");
    
    // //Insertion
    // printf("Inserción\n");
    // for (int i = 0; i < 19; i++) {   
    //     n = N[i];       
    //     printf("Tiempo con %d numeros \n", n);

    //     time_t begin = time(NULL);

    //     //llama a las funciones de ordenamiento con n numeros a ordenar
    //     insertion(arr, n);

    //     time_t end = time(NULL);
    //     // calculate elapsed time by finding difference (end - begin)
    //     printf("Tiempo real: %d segundos\n\n", (end - begin));
    // }
    // printf("\n\n\n");

    // //Shell
    // printf("Shell\n");
    // for (int i = 0; i < 19; i++) {   
    //     n = N[i];       
    //     printf("Tiempo con %d numeros \n", n);

    //     time_t begin = time(NULL);

    //     //llama a las funciones de ordenamiento con n numeros a ordenar
    //     shell(arr, n);

    //     time_t end = time(NULL);
    //     // calculate elapsed time by finding difference (end - begin)
    //     printf("Tiempo real: %d segundos\n\n", (end - begin));
    // }
    // printf("\n\n\n");

    //Quicksort
    // printf("Quicksort\n");
    // for (int i = 0; i < 19; i++) {   
    //     n = N[i];       
    //     printf("Arreglo con %d numeros \n", n);

    //     time_t begin = time(NULL);

    //     //llama a las funciones de ordenamiento con n numeros a ordenar
    //     quicksort(arr, n);

    //     time_t end = time(NULL);
    //     // calculate elapsed time by finding difference (end - begin)
    //     printf("Tiempo real: %d segundos\n\n", (end - begin));
    // }

    return 0;
}