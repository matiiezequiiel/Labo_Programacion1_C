#include <stdio.h>

typedef struct
{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[25];
    char email[20];
} eAlumno;


void mostrarUnAlumno(eAlumno miAlumno);
eAlumno cargarUnAlumno(void);
int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno);
void cargarListadoDeAlumnos(eAlumno listado[], int tam);
void mostrarListadoDeAlumnos(eAlumno listado[], int tam);
void mostrarListadoDeAlumnosPromocionados(eAlumno listado[], int tam, int minAprobado);
void ordenarListadoDeAlumnosPorNombre(eAlumno listado[], int tam);
void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam);
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam);
float calcularMaximoPromedio(eAlumno listado[], int tam);
void mostrarListadoDeAlumnosConMaximo(eAlumno listado[], int tam, int maximo);



