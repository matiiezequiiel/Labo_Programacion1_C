#include <stdio.h>

float sumar(float,float);
float restar(float,float);

int calculadora(float (*pOperacion)(float,float), float, float);



int main()
{


    int funciono;

    funciono = calculadora(sumar,100,700);

    /*........*/

    funciono = calculadora(restar,100,700);

    if(funciono)
    {
        printf("Calculo correcto.");
    }
    else
    {
        printf("No se pudo calcular.");
    }


    return 0;
}



int calculadora(float (*pOperacion)(float,float), float numero1, float numero2)
{

    int calculo = 0;
    float resultado;

    if(pOperacion!=NULL)
    {
        resultado = pOperacion(numero1,numero2);
        printf("El resultado es: %f\n", resultado);
        calculo = 1;
    }

    return calculo;



}



float sumar(float n1, float n2)
{
   return n1+n2;
}
float restar(float n1, float n2)
{
    return n1-n2;
}
