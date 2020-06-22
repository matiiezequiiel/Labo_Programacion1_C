#include <stdio.h>
#include <stdlib.h>

int main()
{


    int* pEntero;
    int* aux;
    int* aux2;

    /* aux2 = (int*) malloc(sizeof(int));

     *aux2 = 100;


     printf("%d\n", *aux2);

     free(aux2);

     printf("%d", *aux2);*/




    int i;

    pEntero= (int*) malloc(sizeof(int)*5);


    if(pEntero!=NULL)
    {
        for(i=0; i<5; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", pEntero+i);
        }

        for(i=0; i<5; i++)
        {
            printf("%d\n", *(pEntero+i));
        }

        printf("Redimensiono el array a 10 elementos\n");
        aux = (int*) realloc(pEntero, sizeof(int)*10);
        if(aux!=NULL)
        {
            pEntero = aux;
            for(i=5; i<10; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", pEntero+i);
            }
            for(i=0; i<10; i++)
            {
                printf("%d\n", *(pEntero+i));
            }
            printf("Redimensiono el array a 3 elementos\n");
            aux = (int*) realloc(pEntero, sizeof(int)*3);
            if(aux!=NULL)
            {
                pEntero = aux;
                for(i=0; i<10; i++)
                {
                    printf("%d\n", *(pEntero+i));
                }
            }

            printf("LIBERO EL AUX\n");
            free(aux);
            for(i=0; i<3; i++)
            {
                printf("%d\n", *(pEntero+i));
            }

        }

    }




    return 0;
}
