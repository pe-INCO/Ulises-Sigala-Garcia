//
//  main.c
//  Practica 14
//
//  Created by Ulises Sigala on 18/03/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int arreglo[10]; // Capacidad máxima de 10 elementos
    int n = 0;       // Cantidad actual de elementos ocupados
    int opcion, valor, posicion, i;
    // Inicializar la semilla para generar números aleatorios diferentes cada vez
    srand(time(NULL));
    do {
        // Mostrar menú
        printf("\n--- MENU DE ARREGLO ---\n");
        printf("1. Inicializar arreglo con 5 valores aleatorios\n");
        printf("2. Mostrar arreglo actual\n");
        printf("3. Agregar elemento al final\n");
        printf("4. Insertar elemento en posicion especifica\n");
        printf("5. Eliminar elemento por posicion\n");
        printf("6. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                n = 5; // Empezamos con 5 elementos
                for(i = 0; i < n; i++) {
                    arreglo[i] = rand() % 100; // Genera números del 0 al 99
                }
                printf("-> Arreglo inicializado con 5 elementos aleatorios.\n");
                break;
            case 2:
                if(n == 0) {
                    printf("-> El arreglo esta vacio.\n");
                } else {
                    printf("-> Contenido del arreglo:\n");
                    for(i = 0; i < n; i++) {
                        printf("[%d]: %d\n", i, arreglo[i]);
                    }
                }
                break;
            case 3:
                if(n < 10) { // Validar que no se pase del límite de 10
                    printf("Ingresa el valor a agregar: ");
                    scanf("%d", &valor);
                    arreglo[n] = valor; // Se guarda en la última posición disponible
                    n++;                // Aumentamos el contador de elementos
                    printf("-> Elemento agregado exitosamente.\n");
                } else {
                    printf("-> ERROR: El arreglo ya esta lleno (10 elementos).\n");
                }
                break;
            case 4:
                if(n < 10) {
                    printf("Ingresa la posicion donde quieres insertar (0 a %d): ", n);
                    scanf("%d", &posicion);
                    // Validar que la posición sea correcta
                    if(posicion >= 0 && posicion <= n) {
                        printf("Ingresa el nuevo valor: ");
                        scanf("%d", &valor);
                        // Mover los elementos hacia la derecha para hacer espacio
                        for(i = n; i > posicion; i--) {
                            arreglo[i] = arreglo[i-1];
                        }
                        arreglo[posicion] = valor; // Insertar el nuevo valor
                        n++;                       // Aumentar el tamaño actual
                        printf("-> Elemento insertado exitosamente.\n");
                    } else {
                        printf("-> ERROR: Posicion invalida.\n");
                    }
                } else {
                    printf("-> ERROR: El arreglo ya esta lleno.\n");
                }
                break;
            case 5:
                if(n > 0) {
                    printf("Ingresa la posicion del elemento a eliminar (0 a %d): ", n - 1);
                    scanf("%d", &posicion);
                    // Validar que la posición exista
                    if(posicion >= 0 && posicion < n) {
                        // Mover los elementos hacia la izquierda para "aplastar" el borrado
                        for(i = posicion; i < n - 1; i++) {
                            arreglo[i] = arreglo[i+1];
                        }
                        n--; // Reducir el tamaño actual
                        printf("-> Elemento eliminado exitosamente.\n");
                    } else {
                        printf("-> ERROR: Posicion invalida.\n");
                    }
                } else {
                    printf("-> ERROR: El arreglo ya esta vacio.\n");
                }
                break;
            case 6:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("-> ERROR: Opcion invalida. Intenta de nuevo.\n");
        }
    } while(opcion != 6);
    return 0;
}
