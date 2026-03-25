//
//  main.c
//  Practica 15
//
//  Created by Ulises Sigala on 25/03/26.
//

#include <stdlib.h>
#include <stdio.h>

// Variables globales
int arreglo[10] = {11, 34, 56, 78, 90, 12, 23, 45, 87, 38};
int numero_buscado;
int encontrado = 0;
int posicion;

void busqueda() {
    for (int i = 0; i < 10; i++) {
        if (arreglo[i] == numero_buscado) {
            encontrado = 1;
            posicion = i;
            break; // Salimos del ciclo en cuanto lo encontramos
        }
    }
}

int main(void) {
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &numero_buscado);

    // Llamamos a la función de búsqueda
    busqueda();

    // Mostramos los resultados
    if (encontrado == 1) {
        printf("¡Numero encontrado! El numero %d esta en la posicion (indice) %d.\n", numero_buscado, posicion);
    } else {
        printf("El numero %d no se encuentra en el arreglo.\n", numero_buscado);
    }

    return 0;
}
