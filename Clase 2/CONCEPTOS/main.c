#include <stdio.h>
#include <stdlib.h>

int main()
{
  /*  int numero;
    float flotante;

    flotante=3.25;
    numero=(int)flotante; // CONVERSION EXPLICITA, CASTEO EL FLOTANTE A ENTERO.
    printf("%d", numero);

*/
    int num1,num2,suma,resta,producto;
    float division;

    printf("Ingrese el primer numero: ");
    scanf("%d",&num1);

    printf ("Ingrese el segundo numero: ");
    scanf("%d",&num2);

    suma=num1+num2;
    resta=num1-num2;
    producto=num1*num2;
    division=(float)num1/num2; // DEBO CASTEAR PORQUE SI NO, NO ME TOMA LA PARTE DECIMAL DE LA DIVISION.

    printf("\n\nLa suma es: %d", suma);
    printf("\nLa resta es: %d", resta);
    printf("\nLa multipliacion es: %d", producto);
    printf("\nLa division es %.2f", division);

    return 0;

}
