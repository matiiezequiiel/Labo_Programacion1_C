#include "Productos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void harcodearProducto(eProducto listaProductos[],int sizeArray)
{

    char hardcodeoNombre[10][20]={"Mani","Porotos","Lentejas","Garbanzos","Maiz","Arvejas","Arroz","Tomate","Lechuga","Avena"};
    float precio[10]={10,12.5,19,1.5,10,11,14,19,20,25};
    int stock[10]={5,6,8,0,6,8,1,25,69,45} ;
    int idProv[10]={1,1,1,1,2,2,2,2,3,3};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0;i<sizeArray;i++)
    {
        strcpy(listaProductos[i].nombre,hardcodeoNombre[i]);
        listaProductos[i].precio=precio[i];
        listaProductos[i].stock=stock[i];
        listaProductos[i].IdProv=idProv[i];
        listaProductos[i].estado=estado[i];
    }

}
int buscarLibreProductos(eProducto listaProductos[],int sizeProductos)
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<sizeProductos;i++)
        {
            if(listaProductos[i].estado==0)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;

}

