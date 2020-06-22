#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Alumno.h"
#define TEMPLEADO 20




int main()
{
    eEmpleado* arrayPunterosEmpleados[TEMPLEADO];
    int posicionLibre;
    int indiceAux;

    //INICIALIZACION ARRAY.
    if(!initArrayPunteros(arrayPunterosEmpleados,TEMPLEADO))
    {
        printf("INIT OK\n\n");
       /* posicionLibre=buscarLibreArrayPunteros(arrayPunterosEmpleados,TEMPLEADO);
        if(posicionLibre!=-1)
        {
            arrayPunterosEmpleados[posicionLibre]=nuevoEmpleadoConParam("Juan","Paco",25,50000,0);
        }*/

        agregarAlumnoEnArrayPunteros(arrayPunterosEmpleados,TEMPLEADO,"Juan","Gonzalez",25,10000,0);

        posicionLibre=buscarLibreArrayPunteros(arrayPunterosEmpleados,TEMPLEADO);
        if(posicionLibre!=-1)
        {
            arrayPunterosEmpleados[posicionLibre]=nuevoEmpleadoConParam("Ana","Ramirez",20,30000,1);
        }

        imprimirArrayPunteros(arrayPunterosEmpleados,TEMPLEADO);
        indiceAux=buscarEnArrayPunterosPorId(arrayPunterosEmpleados,TEMPLEADO,0);
        if(indiceAux!=-1)
        {
            eliminarEmpleadoDeArrayPunterosConIndice(arrayPunterosEmpleados,TEMPLEADO,indiceAux);
            /*  if (!eliminarEmpleadoDeArrayPunteros(arrayPunterosEmpleados,TEMPLEADO,indiceAux))
              {
                  printf("Eliminado correctamente.")
              }*/
        }

        printf("\nEMPLEADOS DESPUES DE ELIMINAR.\n");
        imprimirArrayPunteros(arrayPunterosEmpleados,TEMPLEADO);

    }

    /*  //BUSCAR POSICION LIBRE.
      posicionLibre=buscarLibreArrayPunteros(arrayPunterosEmpleados,TEMPLEADO);
      if(posicionLibre!= -1)
      {
          printf("\nPosicion libre: %d",posicionLibre);
      }
      else
      {
          printf("No hay espacio libre.");
      }
    */

    return 0;
}

