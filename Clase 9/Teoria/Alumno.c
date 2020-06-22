#include "Alumno.h"
eFecha pedirFecha(void)
{
    eFecha miFecha;

    printf("Ingrese dia: ");
    scanf("%d", &miFecha.dia);

    printf("Ingrese mes: ");
    scanf("%d", &miFecha.mes);

    printf("Ingrese anio: ");
    scanf("%d", &miFecha.anio);

    return miFecha;

}

void inicializarAlumnos(eAlumno listaAlumnos[], int tam)
{
     int i;
  for(i=0;i<tam;i++)
  {
      listaAlumnos[i].estado = LIBRE;
  }
}

void eliminarAlumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0;i<tam; i++)
    {
        if(listado[i].estado == OCUPADO && legajo == listado[i].legajo)
        {
            listado[i].estado = LIBRE;
            break;
        }
    }

}

void modificarAlumno(eAlumno listado[], int tam)
{
     int legajo;
    int i;

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0;i<tam; i++)
    {
        if(listado[i].estado == OCUPADO && legajo == listado[i].legajo)
        {
              printf("Ingrese nombre: ");
            fflush(stdin);
            fgets(listado[i].nombre,25,stdin);
            listado[i].nombre[strlen( listado[i].nombre)-1]='\0';
            break;
        }
    }
}

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
    fgets(miAlumno.nombre,25,stdin);
    miAlumno.nombre[strlen( miAlumno.nombre)-1]='\0';
    printf("Ingrese email: ");
    fflush(stdin);
    fgets(miAlumno.email,20,stdin);
    miAlumno.email[strlen( miAlumno.email)-1]='\0';


    miAlumno.fechaNacimiento = pedirFecha();


    miAlumno.promedio = (float)(miAlumno.nota1+miAlumno.nota2)/2;

    //Mostrar los cursos disponibles (Tiene que ser dinamico)
    printf("Ingrese el curso: ");
    scanf("%d", &miAlumno.idCurso);


    miAlumno.estado = OCUPADO;


    return miAlumno;
}

void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%8d %8d %8d %10f %20s %20s %4d [%d/%d/%d]\n", miAlumno.legajo,
                                                           miAlumno.nota1,
                                                           miAlumno.nota2,
                                                           miAlumno.promedio,
                                                           miAlumno.nombre,
                                                           miAlumno.email,
                                                           miAlumno.idCurso,
                                                           miAlumno.fechaNacimiento.dia,
                                                           miAlumno.fechaNacimiento.mes,
                                                           miAlumno.fechaNacimiento.anio);
    }

int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    return unAlumno.legajo == otroAlumno.legajo;

}
int buscarLibre(eAlumno* listado, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
//convertir la funcion a un retorno entero
void cargarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int encontro;
    encontro = buscarLibre(listado,tam);
    if(encontro!=-1)
    {
       listado[encontro] = cargarUnAlumno();
    }
    else
    {
        printf("No hay espacio");
    }

}
void mostrarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
       if(listado[i].estado == OCUPADO)
        {
            mostrarUnAlumno(listado[i]);
        }

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

/********************************************************/


