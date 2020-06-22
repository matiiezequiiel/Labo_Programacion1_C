
#include <stdlib.h>

#include "Alumno-Curso.h"

#define T 5

int
main ()
{
  eAlumno listaAlumnos[T]= {  {100, 7, 9, 8, "Maria", "maria@gmail.com",{10,2,1990},100,OCUPADO},
                              {101, 10, 10, 10, "Juan","juan@gmail.com",{15,12,1996},100,OCUPADO},
                              {102, 7, 7, 7, "Ana", "ana@gmail.com",{7,2,1999},101,OCUPADO},
                              {104, 10, 10, 10, "Ana", "ana1@gmail.com",{14,3,1990},102,OCUPADO},
                              {105, 8, 8, 8, "Ana","ana2@gmail.com",{1,1,1990},101,OCUPADO}};

  eCurso listaCursos[3] = {{100,"Java",10},{101,"Inkscape",5},{102,"Office",8}};
  int opcion;
  int i;
 //inicializarAlumnos(listaAlumnos, T);

  do
    {
      printf ("1.Cargar un ALUMNO\n");
      printf ("2.Eliminar un ALUMNO\n");
      printf ("3.Modificar un ALUMNO\n");
      printf ("4.Listar ALUMNOS\n");
      printf ("5.Ordenar ALUMNOS\n");
      printf ("6.Mostrar CURSOS\n");
     printf ("7.Mostrar ALUMNOS CON SU CURSO\n");
      printf ("10.SALIR\n");
      printf ("ELIJA UNA OPCION: ");
      scanf ("%d", &opcion);
      switch (opcion)
	  {
    	case 1:

    	  printf ("CARGA DE DATOS:\n");
    	  cargarListadoDeAlumnos (listaAlumnos, T);
    	  break;
    	case 2:
    	 eliminarAlumno(listaAlumnos,T);
    	  break;
    	  break;
    	case 3:
    	modificarAlumno(listaAlumnos,T);
    	  break;
    	case 4:
    	  printf ("MUESTRO LISTA DE ALUMNOS\n");
    	  mostrarListadoDeAlumnos (listaAlumnos, T);
    	  break;
    	case 5:
    	  printf ("LISTADO ORDENADO:\n");
    	  ordenarListadoDeAlumnosPorNombre (listaAlumnos, T);
    	  break;
    	 case 6:
    	  mostrarTodosLosCursos(listaCursos,3);
    	 break;
    	 case 7:
    	    mostrarAlumnosConSuCurso(listaAlumnos, T, listaCursos, 3);
    	 break;
    	  case 8:
    	    mostrarCursosConSusAlumnos(listaAlumnos, T, listaCursos, 3);
    	 break;
    	 case 9:
            mostrarCursoConMayorCantidadDeAlumnos(listaAlumnos, T, listaCursos, 3);
    	 break;
	    }

    }while (opcion != 10);



  /* printf("CARGO LISTA DE ALUMNOS\n");
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
     mostrarAlumnosConMaximoPromedio(listaAlumnos,T); */


  return 0;
}
