
#include "Alumno.h"

#include "Curso.h"

typedef struct
{
  int idCurso;
  int cantidadAlumnos;
} eAux;

void mostrarAlumnosConSuCurso(eAlumno[], int, eCurso[], int);
void mostrarCursosConSusAlumnos(eAlumno[], int, eCurso[], int);
void mostrarCursoConMayorCantidadDeAlumnos(eAlumno[], int, eCurso[], int);
