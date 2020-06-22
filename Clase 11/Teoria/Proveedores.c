#include "Proveedores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void harcodearProveedores(eProveedor listaProveedores[],int sizeArray)
{

    char hardcodeoNombre[4][30]={"Fabrica Avellaneda","Fabrica Lanus","Fabrica Banfield","Fabrica Burzaco"};
    char localidad[4][20]={"Avellaneda","Lanus","Banfield","Burzaco"};
    int estado[4]={1,1,1,1};
    int i;


    for(i=0;i<4;i++)
    {
        strcpy(listaProveedores[i].nombre,hardcodeoNombre[i]);
        strcpy(listaProveedores[i].localidad,localidad[i]);
        listaProveedores[i].id=i+1;
        listaProveedores[i].estado=estado[i];


    }

}
void mostrarProveedores(eProveedor listaProveedor[],int sizeProveedores)
{
    int i;
    int proveedores=0;

    for(i=0;i<sizeProveedores;i++)
    {
        if(listaProveedor[i].estado==1)
        {
            printf("Nombre de el proveedor: %s\n",listaProveedor[i].nombre);
            printf("ID del proveedor: %d\n",listaProveedor[i].id);

            proveedores++;
        }

    }
    if(proveedores==0)
    {
        printf("No se encontraron proveedores cargodas.");
    }
    system("pause");
}
