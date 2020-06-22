#include "Productos.h"
#include "Proveedores.h"

typedef struct
{
    int idProveedor;
    int cantProductos;
}eAux;
void mostrarProvConSusProductos(eProducto[],int,eProveedor[],int);
void proveedorMasProductos(eProducto[],int,eProveedor[],int);
void inicializarArray(eProducto[],int,eProveedor[],int);
int altaProducto(eProducto[],int,eProveedor[],int);
