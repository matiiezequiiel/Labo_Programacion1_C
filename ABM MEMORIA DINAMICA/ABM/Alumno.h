typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;
    float sueldo;
    int id;
}eEmpleado;


int initArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado);
int buscarLibreArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado);
void imprimirArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado);
int eliminarEmpleadoDeArrayPunterosConIndice(eEmpleado* arrayEmpleados[],int sizeEmpleado,int indiceEliminar);
void alumnoDelete(eEmpleado* this);
int buscarEnArrayPunterosPorId(eEmpleado* arrayEmpleados[],int sizeEmpleado,int idBuscar);
int agregarAlumnoEnArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado,char* nombre,char* apellido,int edad,float sueldo,int id);
int empleadoSetNombre(eEmpleado* this,char* nombre);
int empleadoGetNombre(eEmpleado* this,char* nombre);
eEmpleado* nuevoEmpleado(void);
eEmpleado* nuevoEmpleadoConParam(char* nombre,char* apellido,int edad,float sueldo,int id);
