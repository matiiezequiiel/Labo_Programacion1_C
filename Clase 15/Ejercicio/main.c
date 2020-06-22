#include <stdio.h>
#include <stdlib.h>

/*
Crear una funcion que reciba como parámetro un numero y permita incrementar en uno ese valor.
La función devolverá un entero informando si pudo o no incrementar dicho numero.
*/

int incrementar(int*);
int main()
{
    int contador = 0;


    if(incrementar(&contador))
    {
        printf("contador incrementado: %d", contador);
    }
    else
    {
        printf("Puntero no inicializado.");
    }

    return 0;
}
int incrementar(int* variable)
{
    int pudo = 0;
    if(variable!=NULL)
    {
        *variable+=1;
        pudo = 1;
    }

   return pudo;
}

 //*variable = *variable + 1; OK
   //(*variable)++; OK
   //variable++; X
   //*variable++; X

