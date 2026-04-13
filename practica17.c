//
//  main.c
//  Practica 17
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

// Función de Ordenamiento por Inserción
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        // Mueve los elementos mayores que la clave a la derecha
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Inserta la clave en su lugar
        arr[j + 1] = clave;
    }
}

// Bloque principal
int main() {
    int arreglo[] = {12, 11, 13, 5, 6};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("--- ORDENAMIENTO POR INSERCION ---\n");
    printf("Arreglo original: ");
    imprimirArreglo(arreglo, tamano);
    
    insertionSort(arreglo, tamano);
    
    printf("Arreglo ordenado: ");
    imprimirArreglo(arreglo, tamano);

    return 0;
}
