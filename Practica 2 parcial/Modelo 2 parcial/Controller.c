#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesUtiles.h"
#include "LinkedList.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include "Controller.h"

int controller_cargarArchivos(char* path, LinkedList* pArrayListVuelos)
{
    //ABRIR ARCHIVOS
    FILE* fileArchivo;
    char cabeceraIdVuelo[20];
    char cabeceraIdAvion[20];
    char cabeceraIdPiloto[20];
    char cabeceraFecha[20];
    char cabeceraDestino[20];
    char cabeceraCantPasajeros[20];
    char cabeceraHoraDespegue[20];
    char cabeceraHoraLlegada[20];
    int retorno=0;

    if(pArrayListVuelos != NULL)
    {
        fileArchivo=fopen(path,"r");

        if(fileArchivo!=NULL)
        {
            printf("Archivo abierto correctamente.\n");

            fscanf(fileArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",cabeceraIdVuelo,cabeceraIdAvion,cabeceraIdPiloto,cabeceraFecha,
                                                                                    cabeceraDestino,cabeceraCantPasajeros,cabeceraHoraDespegue,cabeceraHoraLlegada);
            if(parser_VueloFromText(fileArchivo,pArrayListVuelos))
            {
                retorno=1;
            }
            else
            {
                retorno=0;
            }
        }
        else
        {
            printf("No se pudo abrir el archivo.");
        }
        fclose(fileArchivo);
    }

    return retorno;
}


int parser_VueloFromText(FILE* pFile, LinkedList* pArrayListVuelos)
{
    char idVuelo[5];
    char idAvion[5];
    char idPiloto[5];
    char fecha[11];
    char destino[30];
    char cantPasajeros[5];
    char horaDespegue[5];
    char horaLlegada[5];
    int retorno=0;
    eVuelo* pVuelo;

    while(!feof(pFile))
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino
                                                                        ,cantPasajeros,horaDespegue,horaLlegada);


        pVuelo=vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);

        if(pVuelo!=NULL && pArrayListVuelos!=NULL)
        {
            ll_add(pArrayListVuelos,pVuelo);
            retorno=1;
        }
    }

    return retorno;

}


int controller_ListVuelos(LinkedList* pArrayListVuelos,ePiloto listaPilotos[])
{
    eVuelo* vuelo;
    int contMostrados=0;

    printf("ID VUELO ID AVION  NOMBRE Y APE PILOTO     FECHA VUELO     DESTINO      CANT PASAJEROS    HORA DESPEGUE  HORA LLEGADA");
    for(int i=0;i<ll_len(pArrayListVuelos);i++)
    {

        if(contMostrados==100)
        {
            printf("\nLista de vuelos muy larga, se mostraran de 100 vuelos por vez.");
            printf("\n\n");
            system("pause");
            contMostrados=0;

        }
        vuelo=ll_get(pArrayListVuelos,i);
        mostrarVuelos(vuelo,listaPilotos);
        contMostrados++;


    }
    printf("\n\nFIN DE LA LISTA");
    printf("\n\n");
    system("pause");
    return 1;
}

int controller_cantPasajeros(LinkedList* pArrayListVuelos)
{
    int opcion;
    int retorno;
    char entrada[5];
    int cantidadPasajeros=0;

    printf("Ingrese 1 para conocer la cantidad de pasajeros total en cada vuelo.");
    printf("\nIngrese 2 para conocer la cantidad de pasajeros total a Irlanda.");
    printf("\n\nIngrese opcion: " );
    gets(entrada);

    opcion=validarIntEntreRangos(entrada,1,2);

    switch(opcion)
    {
    case 1:
        cantidadPasajeros=ll_count(pArrayListVuelos,cantidadPasajerosTotal);
        printf("La cantidad de pasajeros totales es de: %d \n\n",cantidadPasajeros);
        system("pause");
        retorno=1;
        break;
    case 2:
        cantidadPasajeros=ll_count(pArrayListVuelos,cantidadPasajerosDestino);
        printf("La cantidad de pasajeros a Irlanda es de: %d \n\n",cantidadPasajeros);
        system("pause");
        retorno=1;
        break;
    }

    return retorno;
}

