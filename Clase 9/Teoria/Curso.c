
#include "Curso.h"

void mostrarTodosLosCursos(eCurso listaDeCursos[], int sizeCursos)
{
    int i;
 for(i=0; i<sizeCursos; i++)
    	  {
    	      printf("%4d %15s %4d\n", listaDeCursos[i].idCurso, listaDeCursos[i].descripcion, listaDeCursos[i].duracion);
    	  }
}

