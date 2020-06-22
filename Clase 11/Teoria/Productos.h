typedef struct
{
    char nombre[20];
    float precio;
    int stock;
    int IdProv;
    int estado;

}eProducto;

void harcodearProducto(eProducto[],int);
int buscarLibreProductos(eProducto[],int);

