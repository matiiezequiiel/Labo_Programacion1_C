#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TPROD 10
#define TPROV 4
#include "Proveedor-Producto.h"


int main()
{
    eProducto productos[TPROD];
    eProveedor proveedores[TPROV];
    int opcion;
    int retorno;

    //inicializarArray(productos,TPROD,proveedores,TPROV);
     harcodearProducto(productos,TPROD);
     harcodearProveedores(proveedores,TPROV);



    do
    {

            system("cls");
            printf("1 ALTA PRODUCTO.\n");
            printf("2 MOSTRAR PROV CON SUS PRODUCTOS.\n");
            printf("3 PROVEEDOR CON MAS PRODUCTOS\n");


            printf("\n\nIngrese su opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                   retorno=altaProducto(productos,TPROD,proveedores,TPROV);
                    if(retorno)
                    {
                        printf("Se ingreso correctamente el producto.\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("La operacion fue cancelada, reeingrese el producto.\n\n");
                        system("pause");
                    }
                break;
                case 2:
                 mostrarProvConSusProductos(productos,TPROD,proveedores,TPROV);
                break;
                case 3:
                proveedorMasProductos(productos,TPROD,proveedores,TPROV);
                break;
            }
    }while(opcion!=10);
}


