
#include <stdio.h>


typedef struct
{
    int entero;;
    char caracter;
}eDato;

int main()
{


   /* eDato vector[2] = {{1,'F'},{1,'G'}};
    eDato* miPunteroDato;
    int i;

    miPunteroDato = vector;

    for(i=0; i<2; i++)
    {
        printf("%d - %c\n", (*(miPunteroDato+i)).entero, (*(miPunteroDato+i)).caracter);
    }
    */


    eDato vector[2] = {{1,'F'},{1,'G'}};
    eDato* miPunteroDato;
    int i;

    miPunteroDato = vector;

    for(i=0; i<2; i++)
    {
       // printf("%d - %c\n", (*(miPunteroDato+i)).entero, (*(miPunteroDato+i)).caracter);
       printf("%d - %c\n", (miPunteroDato+i)->entero, (miPunteroDato+i)->caracter);
    }


    /*eDato miDato = {1,'F'};

    eDato* miPunteroDato;


    miPunteroDato = &miDato;

    printf("%d - %c", (*miPunteroDato).entero, (*miPunteroDato).caracter);*/

 /*eDato miDato = {1,'F'};

    eDato* miPunteroDato;


    miPunteroDato = &miDato;

    printf("%d - %c", miPunteroDato->entero, miPunteroDato->caracter);*/
}

