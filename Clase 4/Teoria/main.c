#include <stdio.h>
#include <stdlib.h>
#include"Funciones.h"

/*BIBLIOTECAS*/

int main()
{
    int numero;

    unsigned long long int resultado;


    numero=getInt("numero para calcular factorial",0,65);

    resultado=factorial(numero);

    printf("El factorial es: %llu", resultado);
    return 0;
}
