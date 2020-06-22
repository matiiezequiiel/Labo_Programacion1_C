#include "Alumno-Curso.h"

void mostrarAlumnosConSuCurso(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listadoDeCursos[], int sizeCursos)
{
    int i;//Alumnos
    int j;//Cursos

    for(i=0; i<sizeAlumnos; i++)
    {
        for(j=0; j<sizeCursos; j++)
        {
            if(listaDeAlumnos[i].estado == OCUPADO && listaDeAlumnos[i].idCurso /*FK*/ == listadoDeCursos[j].idCurso /*PK*/)
            {
                 printf("%4d %15s %15s\n", listaDeAlumnos[i].legajo, listaDeAlumnos[i].nombre, listadoDeCursos[j].descripcion);
                break;

            }

        }
    }

}


void mostrarCursosConSusAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listadoDeCursos[], int sizeCursos)
{
     int i;//Cursos
    int j;//Alumnos

    for(i=0; i<sizeCursos; i++)
    {
        printf("%s\n", listadoDeCursos[i].descripcion);
        for(j=0; j<sizeAlumnos; j++)
        {
            if(listaDeAlumnos[j].estado == OCUPADO && listaDeAlumnos[j].idCurso /*FK*/ == listadoDeCursos[i].idCurso /*PK*/)
            {
                 printf("%4d %15s\n", listaDeAlumnos[j].legajo, listaDeAlumnos[j].nombre);


            }

        }
    }
}

void mostrarCursoConMayorCantidadDeAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listadoDeCursos[], int sizeCursos)
{
    eAux auxiliarAlumnos_Curso[sizeCursos];

    int i;
    int j;
    int maximo;

    listaDeAlumnos[0].estado = LIBRE;
    for(i=0; i<sizeCursos; i++)
    {
        auxiliarAlumnos_Curso[i].idCurso = listadoDeCursos[i].idCurso;
        auxiliarAlumnos_Curso[i].cantidadAlumnos = 0;
    }

    for(i=0; i<sizeCursos; i++)//
    {
        for(j=0; j<sizeAlumnos; j++)
        {
            if(listaDeAlumnos[j].estado==OCUPADO && listaDeAlumnos[j].idCurso == auxiliarAlumnos_Curso[i].idCurso)//Alumno no este dado de baja
            {
                auxiliarAlumnos_Curso[i].cantidadAlumnos++;
            }
        }
    }

    for(i=0; i<sizeCursos; i++)
    {
        if(i==0 || auxiliarAlumnos_Curso[i].cantidadAlumnos>maximo)
        {
            maximo = auxiliarAlumnos_Curso[i].cantidadAlumnos;
        }
    }


    for(i=0; i<sizeCursos; i++)
    {
        for(j=0; j<sizeCursos; j++)
        {
            if(listadoDeCursos[j].idCurso == auxiliarAlumnos_Curso[i].idCurso && auxiliarAlumnos_Curso[i].cantidadAlumnos == maximo)
            {

                printf("%s\n", listadoDeCursos[j].descripcion);

            }
        }
    }


   /* printf("\nMAXIMO %d\n", maximo);

     for(i=0; i<sizeCursos; i++)
    {
        printf("%d--%d\n",auxiliarAlumnos_Curso[i].idCurso, auxiliarAlumnos_Curso[i].cantidadAlumnos );
    }*/

}








