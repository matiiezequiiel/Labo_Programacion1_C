#include "Proveedor-Producto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarArray(eProducto listaProductos[],int sizeProducto,eProveedor listaProveedor[],int sizeProveedor)
{
    int i;


    for(i=0;i<sizeProducto;i++)
    {
        listaProductos[i].IdProv=i+1;
        listaProductos[i].estado=0;
    }
      for(i=0;i<sizeProveedor;i++)
    {
        listaProveedor[i].id=0;
        listaProductos[i].estado=0;
    }

}
void mostrarProvConSusProductos(eProducto listaProductos[],int sizeProd,eProveedor listaProveedor[],int sizeProv)
{
    int i;
    int j;
    int contProductos;

    for(i=0;i<4;i++)
    {
        printf("\nProvedor: %s",listaProveedor[i].nombre);
        contProductos=0;

        for(j=0;j<10;j++)
        {

            if(listaProveedor[i].id==listaProductos[j].IdProv && listaProductos[j].estado==1)
            {
                printf("\n%s---%.2f---%d",listaProductos[j].nombre,listaProductos[j].precio,listaProductos[j].stock);
                contProductos++;
            }
        }

        if(contProductos==0)
        {
            printf("\nNo tiene producto.");
        }
    }

}


void proveedorMasProductos(eProducto listaProductos[],int sizeProducto,eProveedor listaProveedores[],int sizeProveedor)
{
    eAux auxProvProd[4];
    int i;
    int j;
    int maximo=0;

    for(i=0; i<sizeProveedor; i++)
    {
        auxProvProd[i].idProveedor = listaProveedores[i].id;
        auxProvProd[i].cantProductos = 0;
    }

     for(i=0; i<sizeProveedor; i++)//
    {
        for(j=0; j<sizeProducto; j++)
        {
            if(auxProvProd[i].idProveedor == listaProductos[j].IdProv && listaProductos[j].estado==1)
            {
                auxProvProd[i].cantProductos++;
            }
        }
    }

    for(i=0; i<sizeProveedor; i++)
    {
        if(i==0 || auxProvProd[i].cantProductos>maximo)
        {
            maximo = auxProvProd[i].cantProductos;
        }
    }

    printf("\n\nMAXIMO\n");

    for(i=0; i<sizeProveedor; i++)
    {

            if(listaProveedores[i].id == auxProvProd[i].idProveedor && auxProvProd[i].cantProductos == maximo)
            {


                printf("\n%s-----%d", listaProveedores[i].nombre,auxProvProd[i].cantProductos);

            }

    }



}

int altaProducto(eProducto listaProductos[],int sizeProductos,eProveedor listaProveedor[],int sizeProveedor)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreProductos(listaProductos,sizeProductos);

    system("cls");

    if(posicionLibre!=-1)

    {
        printf("Ingrese nombre de el producto: ");
        fflush(stdin);
        gets(listaProductos[posicionLibre].nombre);
        printf("\nIngrese precio: ");
        scanf("%f",&listaProductos[posicionLibre].precio);
        printf("\nIngrese stock del producto: ");
        scanf("%d",&listaProductos[posicionLibre].stock);
        system("cls");
        printf("Proveedores activos actualmente:\n ");
        mostrarProveedores(listaProveedor,sizeProveedor);
        printf("\n\nIngrese ID del proveedor del producto: ");
        scanf("%d",&listaProductos[posicionLibre].IdProv);


        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        scanf("%d",&confirmacion);

        if (confirmacion==1)
        {
            listaProductos[posicionLibre].estado=1;
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }



}





