#include <stdio.h>
#include <stdlib.h>

/*
TIPOS DE DATOS 
INT
FLOAT
CHAR 
/*

MASCARA PARA DATOS 

%d = ENTEROS
%f = FLOAT 
%c = CARACTER
*/


int main(int argc, char *argv[]) 
{
 	int edad;
	float altura;
	char sexo;
	
	
	printf("Ingrese la edad: ");
	fflush(stdin);
	//fflush(stdin); PARA LIMPIAR BUFFER, USAR SIEMPRE ANTES DE SCANF.
	scanf("%d",&edad);
	printf("La edad es: %d", edad);
	
	printf("\n\nIngrese la altura: ");
	fflush(stdin);
	scanf("%f",&altura);
	printf("La altura es: %.2f", altura);   // REDONDEA PARA ARRIBA LA MASCARA %.1f ALT+92 = CONTRABARRA
	//printf("\nLa altura es: %.2f",&altura); // PARA VER LA DIRECCION DE MEMORIA DONDE ESTA GUARDADO ALTURA. EL & APUNTA A LA DIRECCION DE MEMORIA
	
	printf("\n\nIngrese el sexo: ");
	fflush(stdin);
	scanf("%c",&sexo);
	printf("El sexo es: %c", sexo);


	return 0;
}
