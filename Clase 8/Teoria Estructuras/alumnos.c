#include "alumnos.h"

eAlumno cargarUnAlumno(void)
{
    eAlumno miAlumno;
    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nota 1: ");
    scanf("%d", &miAlumno.nota1);
    printf("Ingrese nota 2: ");
    scanf("%d", &miAlumno.nota2);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("Ingrese email: ");
    fflush(stdin);
    gets(miAlumno.email);
    miAlumno.promedio = (float)(miAlumno.nota1+miAlumno.nota2)/2;

    return miAlumno;
}

void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%8d %8d %8d %10f %20s %20s\n", miAlumno.legajo,
                                           miAlumno.nota1,
                                           miAlumno.nota2,
                                           miAlumno.promedio,
                                           miAlumno.nombre,
                                           miAlumno.email);
}

int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    return unAlumno.legajo == otroAlumno.legajo;

}

void cargarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i] = cargarUnAlumno();
    }
}
void mostrarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }

}

void mostrarListadoDeAlumnosPromocionados(eAlumno listado[], int tam, int minAprobado)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio >= minAprobado)
        {
            mostrarUnAlumno(listado[i]);
        }

    }
}

void ordenarListadoDeAlumnosPorNombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
               auxAlumno  =  listado[i];
               listado[i] = listado[j];
               listado[j] = auxAlumno;
            }

        }
    }

}
void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam)
{
     int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
               auxAlumno  =  listado[i];
               listado[i] = listado[j];
               listado[j] = auxAlumno;
            }
            else
            {
               if(strcmp(listado[i].nombre,listado[j].nombre)==0)
               {
                   if(listado[i].promedio>listado[j].promedio)
                   {
                          auxAlumno  =  listado[i];
                          listado[i] = listado[j];
                          listado[j] = auxAlumno;
                   }
               }
            }

        }
    }
}
float calcularMaximoPromedio(eAlumno listado[], int tam)
{
     float maxPromedio ;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio>maxPromedio || i==0)
        {
            maxPromedio = listado[i].promedio;
        }
    }
    return maxPromedio;
}
void mostrarListadoDeAlumnosConMaximo(eAlumno listado[], int tam, int maximo)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio == maximo)
        {
                mostrarUnAlumno(listado[i]);
        }
    }
}
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam)
{
   float maximoPromedio;
   int i;

   maximoPromedio = calcularMaximoPromedio(listado,tam);

   mostrarListadoDeAlumnosConMaximo(listado,tam, maximoPromedio);

}

