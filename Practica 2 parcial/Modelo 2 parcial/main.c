#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pilotos.h"
#include "FuncionesUtiles.h"
#include "Controller.h"


int main()
{
    int opcion;
    int retorno;
    char nombreArchivo[20];
    int archivoCargado=0;
    ePiloto ListaPilotos[5];
    LinkedList* listaVuelos;

    listaVuelos=ll_newLinkedList();
    hardcodearPilotos(ListaPilotos);


    do
    {
        system("cls");
        opcion=mostrarMenuABM();

        switch(opcion)
        {
        case 1:
          //  printf("Ingrese nombre del archivo: ");
          //  gets(nombreArchivo);
            retorno=controller_cargarArchivos("Vuelos.csv",listaVuelos);

            if(!archivoCargado)
            {
                if(retorno)
                {
                    system("cls");
                    printf("\nArchivo cargado correctamente.\n\n");
                    system("pause");
                    archivoCargado=1;
                }
                else
                {
                    system("cls");
                    printf("\nNo se pudo cargar el archivo.\n\n");
                    system("pause");
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado.\n\n");
                system("pause");

            }

            break;

        case 2:
            controller_ListVuelos(listaVuelos,ListaPilotos);
            break;

        case 3:
            controller_cantPasajeros(listaVuelos);
            break;

        case 4:
             controller_cantPasajeros(listaVuelos);
            break;

        case 5:
            controller_filterVuelosCortos(listaVuelos);
            //FALTA CARGAR ARCHIVO

            break;

        case 6:
            break;

        case 7:
            break;

        default:
            break;

        }


    }
    while(opcion != 8);

    return 0;
}
