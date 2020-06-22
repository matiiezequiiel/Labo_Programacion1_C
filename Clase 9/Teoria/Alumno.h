#include <stdio.h>

#define LIBRE 0
#define OCUPADO 1



typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;




typedef struct
{
    int legajo; //PK
    int nota1;
    int nota2;
    float promedio;
    char nombre[25];
    char email[20];

    eFecha fechaNacimiento;


   int idCurso;// FK

    int estado;
} eAlumno;


void inicializarAlumnos(eAlumno[],int);
eFecha pedirFecha(void);
void mostrarUnAlumno(eAlumno miAlumno);

int buscarLibre(eAlumno*, int);
eAlumno cargarUnAlumno(void);
void cargarListadoDeAlumnos(eAlumno listado[], int tam);


void eliminarAlumno(eAlumno listado[], int tam);
void modificarAlumno(eAlumno listado[], int tam);

int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno);
void mostrarListadoDeAlumnos(eAlumno listado[], int tam);
void mostrarListadoDeAlumnosPromocionados(eAlumno listado[], int tam, int minAprobado);
void ordenarListadoDeAlumnosPorNombre(eAlumno listado[], int tam);
void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam);
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam);
float calcularMaximoPromedio(eAlumno listado[], int tam);
void mostrarListadoDeAlumnosConMaximo(eAlumno listado[], int tam, int maximo);

/*********************************/



