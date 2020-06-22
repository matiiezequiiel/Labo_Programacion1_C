#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 10

int main()
{

    int edad;
    int edadDos;
    int arrayEdades[3];


    int edad;
    int edadDos;
    int arrayEdades[3];
    int i;


    for(i=0;i<3;i++) //CARGA SECUENCIAL
    {
        arrayEdades[i]=22*i;
    }
     for(i=0;i<3;i++)
    {
        printf("\n valor del array %d ",arrayEdades[i]);// arrayEdades = &arrayEdades[0]
        printf("\n pubtero del array %d  ",&arrayEdades[i]);

    }


    // CARGA ALEATORIA
    int edad;
    int edadDos;
    int arrayEdades[TAMANIO];
    int i;
    char respuesta;
    int ubicacion;
    char sobreescribir;



    //inicializar en -1
    for(i=0;i<TAMANIO;i++)
    {
        arrayEdades[i]=-1;
    }

    for(i=0;i<TAMANIO;i++)
    {
        printf("\n valor del array %d ",arrayEdades[i]);
    }

    do{

        do{
            printf("\n ingrese la ubicacion del 1 al 10 :");//del 0 al 9  es -1
            scanf("%d",&ubicacion);
        }while(ubicacion<1 || ubicacion>TAMANIO);

        //validar


        if(arrayEdades[ubicacion-1]==-1)
        {
            printf("\nBueno, ahora ingresa la nota: ");
            scanf("%d",&arrayEdades[ubicacion-1]);

        }else
        {
            printf("\nYa esta cargada la nota, quiere sobreescribir??: ");
            __fpurge(stdin);
            scanf("%c",&sobreescribir);
            if(sobreescribir=='s')
            {
                printf("\nBueno, ahora ingresa la nota: ");
                scanf("%d",&arrayEdades[ubicacion-1]);
            }
        }

        printf("\n desea continuar :");
        __fpurge(stdin);
        scanf("%c",&respuesta);
    }while(respuesta=='s');

    printf("\n despues");

    for(i=0;i<TAMANIO;i++)
    {
        printf("\n valor del array %d ",arrayEdades[i]);// arrayEdades = &arrayEdades[0]
       // printf("\n pubtero del array %d  ",&arrayEdades[i]);
    }


    return 0;
}
}
