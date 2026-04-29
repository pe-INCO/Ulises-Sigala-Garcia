//
//  main.c
//  Practica 20
//
//  Created by Ulises Sigala on 29/04/26.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char frase[256];
    char copia[256];
    int longitud;
    printf("Introduce una frase: ");
    if (fgets(frase, sizeof(frase), stdin) != NULL)
    {
        frase[strcspn(frase, "\n")] = '\0';
        longitud = strlen(frase);
        printf("\n--- Resultados ---\n");
        printf("1. Longitud de la cadena: %d caracteres\n", longitud);
        printf("2. Primeros 3 caracteres: ");
        for (int i = 0; i < 3 && i < longitud; i++)
        {
            putchar(frase[i]);
        }
        printf("\n");
        printf("3. Últimos 3 caracteres: ");
        int inicio = (longitud > 3) ? longitud - 3 : 0;
        for (int i = inicio; i < longitud; i++)
        {
            putchar(frase[i]);
        }
        printf("\n");
        strcpy(copia, frase);
        for (int i = 0; copia[i] != '\0'; i++)
        {
            copia[i] = toupper((unsigned char)copia[i]);
        }
        printf("4. Mayúsculas: %s\n", copia);
        strcpy(copia, frase);
        for (int i = 0; copia[i] != '\0'; i++)
        {
            copia[i] = tolower((unsigned char)copia[i]);
        }
        printf("5. Minúsculas: %s\n", copia);
        strcpy(copia, frase);
        for (int i = 0; copia[i] != '\0'; i++)
        {
            if (copia[i] == 'a' || copia[i] == 'A')
            {
                copia[i] = '@';
            }
        }
        printf("6. Reemplazando 'a' por '@': %s\n", copia);
    }
    return 0;
}
