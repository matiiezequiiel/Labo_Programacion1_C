#include <stdio.h>
#include <stdlib.h>

//declaracion o prototipo

/*tipoRetorna nombre(listaParametros);
tipoRetorna: int float char double void
listaParametros: int float char arrays*/


int getInt(char mensaje[],int minimo, int maximo);
//int getInt(char,int, int); ES LO MISMO


int main()
{

    //Llamada
    int edad;
    int legajo;
    int nota;

    edad=getInt("edad",1,18);
    legajo=getInt("legajo",100,666);
    nota=getInt("nota",1,10);

    return 0;
}


//Desarrollo o implementacion


int getInt(char mensaje[],int minimo, int maximo) // Paso el mensaje para que cada pedido pida el dato que necesito.
                                                  //Paso ademas rangos para validar segun pedido.
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
