//
//  main.c
//  Practica 16
//
//  Created by Ulises Sigala on 26/03/26.
//

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    int i,j,temp,n;
    int arreglo[]={50,26,7,9,15,27};
    n = sizeof(arreglo)/sizeof(arreglo[0]);
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (arreglo[i]>arreglo[j]){
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
                printf("%d, ", arreglo[i]);
                printf("%d, ", arreglo[i]);
            }
        }
    }
    for (i=0; i<n-i; i++) {
        printf("%d ,", arreglo[i]);
        }
}
