#include"Alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INICIALIZAR ARRAY DE PUNTEROS EN NULL-
int initArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado)
{
    int i;
    int retorno=-1;

    if(arrayEmpleados!=NULL && sizeEmpleado>0)
    {
        for(i=0; i<sizeEmpleado; i++)
        {
            arrayEmpleados[i]=NULL;
            retorno=0;
        }
    }

    return retorno;

}


//BUSCAR EN UN ARRAY DE PUNTEROS UNA POSICION LIBRE PARA CARGAR
int buscarLibreArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado)
{
    int i;
    int posicionLibre=-1;

    if(arrayEmpleados!=NULL && sizeEmpleado>0)
    {
        for(i=0; i<sizeEmpleado; i++)
        {
            if(arrayEmpleados[i]==NULL)
            {
                posicionLibre=i;
                break;
            }
        }

    }

    return posicionLibre;

}


//IMPRIMIR LOS VALORES ALMACENADOS EN UN ARRAY DE PUNTEROS.
void imprimirArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado)
{
    int i;

    if(arrayEmpleados!=NULL && sizeEmpleado>0)
    {
        for(i=0; i<sizeEmpleado; i++)
        {
            if(arrayEmpleados[i]!=NULL)
            {
                printf("Nombre: %s  Apellido: %s  Edad: %d  Sueldo: %.2f ID:%d\n",arrayEmpleados[i]->nombre,arrayEmpleados[i]->apellido
                       ,arrayEmpleados[i]->edad,arrayEmpleados[i]->sueldo,arrayEmpleados[i]->id);
            }

        }
    }


}


//ELIMINAR UN EMPLEADO BUSCANDO POR EL INDICE.
int eliminarEmpleadoDeArrayPunterosConIndice(eEmpleado* arrayEmpleados[],int sizeEmpleado,int indiceEliminar)
{
    int retorno=-1;

    if(arrayEmpleados!=NULL && indiceEliminar>=0 && indiceEliminar<sizeEmpleado && arrayEmpleados[indiceEliminar]!=NULL)
    {
        alumnoDelete(arrayEmpleados[indiceEliminar]);
        arrayEmpleados[indiceEliminar]=NULL;
        retorno=0;
    }
    return retorno;
}


//LIBERAR MEMORIA DE UN ALUMNO DESPUES DE ELIMINARLO
void alumnoDelete(eEmpleado* this)
{
    free(this);
}

//BUSCAR EN ARRAY DE PUNTEROS EL INDICE EN EL QUE ESTA CARGADO SEGUN ID.
int buscarEnArrayPunterosPorId(eEmpleado* arrayEmpleados[],int sizeEmpleado,int idBuscar)
{
    int i ;
    int retorno=-1;

    if(arrayEmpleados!=NULL && idBuscar>=0 && sizeEmpleado>0)
    {
        for(i=0; i<sizeEmpleado; i++)
        {
            if(arrayEmpleados[i]->id == idBuscar)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;

}

//AGREGAR UN ALUMNO

int agregarAlumnoEnArrayPunteros(eEmpleado* arrayEmpleados[],int sizeEmpleado,char* nombre,char* apellido,int edad,float sueldo,int id)
{
    int posicionLibre=-1;
    int retorno=1;

    posicionLibre=buscarLibreArrayPunteros(arrayEmpleados,sizeEmpleado);

    if(posicionLibre!=-1)
    {
        arrayEmpleados[posicionLibre]=nuevoEmpleadoConParam(nombre,apellido,edad,sueldo,id);
        retorno=0;

    }
    else
    {
        retorno=1;
    }



    return retorno;

}

int empleadoSetNombre(eEmpleado* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        //Validaciones
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;

}

int empleadoGetNombre(eEmpleado* this,char* nombre)
{
     int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        //Validaciones
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}



eEmpleado* nuevoEmpleado(void)
{
    eEmpleado* auxP=NULL;

    auxP=(eEmpleado*)malloc(sizeof(eEmpleado));

    return auxP;
    //return (eEmpleado*)malloc(sizeof(eEmpleado));
}

eEmpleado* nuevoEmpleadoConParam(char* nombre,char* apellido,int edad,float sueldo,int id)
{
    eEmpleado* auxP=NULL;

    auxP=nuevoEmpleado();

    if(auxP!=NULL)
    {
        strcpy(auxP->nombre,nombre);
        strcpy(auxP->apellido,apellido);
        auxP->edad=edad;
        auxP->sueldo=sueldo;
        auxP->id=id;
    }

    return auxP;

}

