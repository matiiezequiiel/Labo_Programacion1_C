#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
/*	FORMA 1

	int numeroUno;
    int numeroDos;
    int numeroTres;
    int mayorValor;
    
    printf("ingrese el primer numero :");
    scanf("%d",&numeroUno);
    
    printf("ingrese el segundo numero :");
    scanf("%d",&numeroDos);
    
    printf("ingrese el tercer numero :");
    scanf("%d",&numeroTres);
    
    
    if(numeroUno>numeroDos&& numeroUno>numeroTres)
    {
        mayorValor=numeroUno;
    }else
    {
        if(numeroDos>numeroTres)
        {
            mayorValor=numeroDos;
        }else
        {
            mayorValor=numeroTres;
        }
    }
    
    printf("el mayor valor es : %d", mayorValor);

*/
 
// FORMA 2

	int contador;
	int mayorValor;
	int numeroIngresado;
	
	for (contador=0; contador<3; contador++) 
	{
		printf("Ingrese el numero %d :",contador+1);
		scanf ("%d",&numeroIngresado);
		
		if(mayorValor<numeroIngresado || contador == 0) //Pregunto primero por el numero porque despoues de la primera iteracion la pregunta del contador sabemos que es falso.
		{
			mayorValor=numeroIngresado;
		}
	}
	
	printf("El numero mayor es: %d", mayorValor);
	
	return 0;
}
