#include <stdio.h>
#include <stdlib.h>

/*Pedirle al usuario que ingrese legajo, altura y sexo y mostrar los datos. (Utilizar 3 funciones distintas para tal cometido)*/

int getInt(char mensaje[],int minimo, int maximo);
float getFloat(char mensaje[],int minimo, int maximo);
char getChar(char mensaje[],char valor1, char valor2);



int main()
{


    int legajo;
    float altura;
    char sexo;

    legajo=getInt("Legajo",1,1000);
    altura=getFloat("Altura",0,2.5);
    sexo=getChar("Sexo", 'f','m');

    return 0;
}



int getInt(char mensaje[],int minimo, int maximo)
{
    int valor;
    printf("Ingrese %s: ", mensaje);
    scanf("%d",&valor);

    while(valor<minimo || valor>maximo)
    {
        printf("Reeingrese %s:", mensaje);
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
        printf("Reeingrese %s:", mensaje);
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
        printf("Reeingrese %s:", mensaje);
        fflush(stdin);
        scanf("%c",& sexo);
    }

    return sexo;

}
