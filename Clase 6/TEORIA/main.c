#include <stdio.h>
#include <stdlib.h>

//Dentro de iteracion: CONTINUE FUERZO A LA SIGUIENTE ITERACION.
//                     BREAK CORTA LA ITERACION Y FUERZA A QUE SALGA


int main()
{
    int vector[]={9,5,1,4};
    int i;
    int j;
    int aux;

    for(i=0;i<4-1;i++)
    {
        //if(vector[i]==-1);
        //   continue; Corta el for y pasa a la siguiente iteracion.
        for(j=i+1;j<4;j++)
        {
            if((vector[i]!=-1 && vector[j]!=-1) && vector[i]>vector[j]) //(vector[i]!=-1 && vector[j]!=-1) PARA OBVIAR LOS CARGADOS CON -1 (VACIOS)
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }

    for(i=0;i<4;i++)
    {
        printf("%d\n",vector[i]);
    }

}
