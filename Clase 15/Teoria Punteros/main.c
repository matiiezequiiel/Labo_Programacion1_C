#include <stdio.h>
#include <stdlib.h>
/*
void swap(int*, int*);
int main()
{
    int a = 10;
    int b = 7;

    swap(&a, &b);
    printf("a: %d - b: %d", a, b);

    return 0;
}
void swap(int* p, int* q)
{
    int c;

     c = *p;
    *p = *q;
    *q = c;
}
*/


/*
int main()
{
    int dato;

    int* punteroDato = NULL;

    punteroDato = &dato; //LinuxDamememoria();//&dato;


   if(punteroDato!=NULL)
   {
        printf("Ingrese un valor: ");
    scanf("%d", punteroDato);
    //*punteroDato = 100;

    printf("dato: %d\n", dato);
   }
   else
   {
       printf("Puntero no asignado");
   }



    printf("dato: %d\n", dato);//Naranja
    printf("dato (*): %d\n", *punteroDato);//naranja
    printf("dir dato: %p\n", &dato);//celeste
    printf("dir punteroDato: %p\n", &punteroDato);//verde
    printf("dir a la que apunta punteroDato: %p\n", punteroDato);//celeste


    return 0;
}

/*

int main()
{

    int miVector[5]={5,7,8,9,1};
    int* puntero;
    int i;

    puntero = miVector; // &miVector // &miVector[0];

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", (puntero+i));


    }



    for(i=0; i<5; i++)
    {
        printf("%d\n", *(puntero+i)); /*ntero[i]);/* */

    }


 /*printf("%d\n", puntero);
    printf("%d\n", puntero+0);
    printf("%d\n", puntero+1);
    printf("%d\n", puntero+2);
    printf("%d\n", puntero+3);

    puntero++;

    printf("\n\n\n%d\n", puntero);
    printf("%d\n", puntero+0);
    printf("%d\n", puntero+1);
    printf("%d\n", puntero+2);
    printf("%d\n", puntero+3);

 */

}
