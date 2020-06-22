#include <stdio.h>
#include <stdlib.h>

/** \brief ¿QUE HACE?
 *
 * \param PARAMETROS
 * \param PARAMETROS
 * \return QUE RETORNA
 *
 */

/** \brief Pide y valida un numero entero.
 *
 * \param char[] Tipo de dato que va a pedir.
 * \param int    Rango minimo para validacion.
 * \param int    Rango maximo para validacion.
 * \return int   Numero entero validado.
 *
 */
int getInt(char mensaje[],int minimo,int maximo)
{
    int valor;
    printf("Ingrese %s: ", mensaje);
    scanf("%d",&valor);

    while(valor<minimo || valor>maximo)
    {
        printf("Error!!, reeingrese %s:", mensaje);
        scanf("%d",& valor);
    }

    return valor;

}

float getFloat(char mensaje[],int minimo, int maximo)
{
    float valor;
    printf("Ingrese %s: ", mensaje);
    scanf("%f",&valor);

    while(valor<minimo || valor>maximo)
    {
        printf("Error!!, reeingrese %s:", mensaje);
        scanf("%f",& valor);
    }

    return valor;

}

char getChar(char mensaje[],char valor1, char valor2)
{
    char sexo;
    printf("Ingrese %s: ", mensaje);
    fflush(stdin);
    scanf("%c",&sexo);

    while(sexo != valor1 && sexo != valor2)
    {
        printf("Error!!,reeingrese %s:", mensaje);
        fflush(stdin);
        scanf("%c",& sexo);
    }

    return sexo;

}

unsigned long long int factorial (int numero)

{
    int i;
    unsigned long long int resultado=1; //ver factorial de 0 y 1



    for(i=numero;i>1;i--)
    {
        if (i==numero)
        {
            i--;
            resultado=numero*i;
        }

        else
        {
            resultado=resultado*i;
        }

    }

    return resultado;

}

