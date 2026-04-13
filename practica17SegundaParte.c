//
//  main.c
//  Practica 17SegundaParte
//
//  Created by Ulises Sigala on 13/04/26.
//

#include <stdio.h>

// Función para imprimir el arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para intercambiar dos valores
void intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

// Función que acomoda el pivote y particiona el arreglo
int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = (bajo - 1);

    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Función principal de Quick Sort (Recursiva)
void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);

        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// Bloque principal
int main() {
    int arreglo[] = {10, 7, 8, 9, 1, 5};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("--- ORDENAMIENTO POR INTERCAMBIO (QUICK SORT) ---\n");
    printf("Arreglo original: ");
    imprimirArreglo(arreglo, tamano);
    
    // Se envía la posición inicial (0) y la final (tamano - 1)
    quickSort(arreglo, 0, tamano - 1);
    
    printf("Arreglo ordenado: ");
    imprimirArreglo(arreglo, tamano);

    return 0;
}
