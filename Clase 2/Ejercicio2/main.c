#include <stdio.h>
#include <stdlib.h>

int main()

{
    /*PARTE A
    Ingreso 5 productos, hay dos tipos "a" y tipo "b" , necesito saber el precio más caro y el promedio de precios


    char producto;
    float maximo;
    int i;
    float precio;
    float acumulador=0;
    float promedio;

    printf("Ingrese el producto 1: ");
    scanf("%c",&producto);

    printf("Ingrese el precio: ");
    scanf("%f",&precio);

    maximo=precio;
    acumulador=precio;

    for(i=1;i<5;i++)
    {
        fflush(stdin);
        printf("Ingrese el producto %d: ",i+1);
        scanf("%c",&producto);

        printf("Ingrese el precio: ");
        scanf("%f",&precio);

        acumulador+=precio;

        if(precio>maximo)
            maximo=precio;

    }

    promedio=acumulador/i;

    printf("El mayor precio es: %.2f",maximo);
    printf("\nEl promedio es: %.2f",promedio);

    return 0;
     */

    /*PARTE B Ingreso 5 productos, hay dos tipos "a" y tipo "b" ,
    necesito saber el promedio de precios de los productos tipo "a"

    char producto;
    int i;
    int productosA=0;
    float precio;
    float acumulador=0;
    float promedio;


    for(i=0;i<5;i++)
    {

        printf("Ingrese el producto %d: ",i+1);
        fflush(stdin);
        scanf("%c",&producto);

        printf("Ingrese el precio: ");
        scanf("%f",&precio);

        if(producto=='a')
        {
            acumulador+=precio;
            productosA++;
        }

    }

    promedio=acumulador/productosA;


    printf("\nEl promedio es: %.2f",promedio);

    return 0;
    */

     /*PARTE C  Ingreso 5 productos, hay dos tipos "a" y tipo "b" ,
     necesito saber si el promedio de precios de los de tipo "a" es mayor o menor o igual al de promedio de precios de
     tipo "b" **/

    char producto;
    int i;
    int productosA=0;
    float precio;
    float acumulador=0;
    float promedio;


    for(i=0;i<5;i++)
    {

        printf("Ingrese el producto %d: ",i+1);
        fflush(stdin);
        scanf("%c",&producto);

        printf("Ingrese el precio: ");
        scanf("%f",&precio);

        if(producto=='a')
        {
            acumulador+=precio;
            productosA++;
        }

    }

    promedio=acumulador/productosA;


    printf("\nEl promedio es: %.2f",promedio);

    return 0;




}
