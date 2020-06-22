#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#define T 5

int main()
{
    eAlumno listaAlumnos[T] = {{100, 7, 9, 8, "Maria", "maria@gmail.com"},{101,10,10,10,"Juan","juan@gmail.com"},{102,7,7,7,"Ana", "ana@gmail.com"},{104,10,10,10,"Ana", "ana1@gmail.com"},{105,8,8,8,"Ana", "ana2@gmail.com"}};
    printf("CARGO LISTA DE ALUMNOS\n");
    //cargarListadoDeAlumnos(listaAlumnos,T);
    printf("MUESTRO LISTA DE ALUMNOS\n");
    mostrarListadoDeAlumnos(listaAlumnos,T);
    printf("MUESTRO LISTA DE ALUMNOS PROMOCIONADOS\n");
    mostrarListadoDeAlumnosPromocionados(listaAlumnos, T, 6);
    printf("MUESTRO LISTA DE ALUMNOS ORDENADO POR NOMBRE\n");
    ordenarListadoDeAlumnosPorNombre(listaAlumnos,T);
    mostrarListadoDeAlumnos(listaAlumnos,T);
    printf("MUESTRO LISTA DE ALUMNOS ORDENADO POR NOMBRE Y LUEGO POR PROMEDIO\n");
    ordenarListadoDeAlumnosPorNombreYporPromedio(listaAlumnos,T);
    mostrarListadoDeAlumnos(listaAlumnos,T);
    printf("MUESTRO LISTA DE ALUMNOS CON MAYOR PROMEDIO\n");
    mostrarAlumnosConMaximoPromedio(listaAlumnos,T);


    return 0;
}
