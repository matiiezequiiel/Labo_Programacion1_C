#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char entrada[20];
    int retorno;

    printf("Ingresa cadena: ");
    gets(entrada);

    retorno=validarCadena(entrada);

    if(retorno)
        printf("\nCadena valida.");
    else
        printf("\nCadena invalida.");


}

