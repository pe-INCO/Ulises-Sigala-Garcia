//
//  main.c
//  LifoFifo
//
//  Created by Ulises Sigala on 16/04/26.
//

#include <stdlib.h>
#include <stdio.h>
#define MAX 5

int main() {
    int arreglo[MAX];
    int opcion, dato;
    int i;
    int modo; // 1 = FIFO, 2 = LIFO
    int size = 0; // cantidad de elementos actuales

    printf("Selecciona el modo:\n");
    printf("1. FIFO (Cola)\n");
    printf("2. LIFO (Pila)\n");
    scanf("%d", &modo);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Encolar/Apilar\n");
        printf("2. Desencolar/Desapilar\n");
        printf("3. Mostrar\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1: // Insertar
                if(size == MAX) {
                    printf("Error: Overflow (estructura llena)\n");
                } else {
                    printf("Ingresa el dato: ");
                    scanf("%d", &dato);
                    arreglo[size] = dato;
                    size++;
                }
                break;
            case 2: // Eliminar
                if(size == 0) {
                    printf("Error: Underflow (estructura vacia)\n");
                } else {
                    if(modo == 1) {
                        // FIFO
                        printf("Elemento eliminado: %d\n", arreglo[0]);
                        for(i = 0; i < size - 1; i++) {
                            arreglo[i] = arreglo[i + 1];
                        }
                        size--;
                    } else if(modo == 2) {
                        // LIFO
                        printf("Elemento eliminado: %d\n", arreglo[size - 1]);
                        size--;
                    }
                }
                break;
            case 3: // Mostrar
                if(size == 0) {
                    printf("Estructura vacia\n");
                } else {
                    printf("Elementos:\n");
                    for(i = 0; i < size; i++) {
                        printf("%d ", arreglo[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 4);

    return 0;
}
