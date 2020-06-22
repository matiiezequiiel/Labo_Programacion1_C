#include <stdio.h>
#include <stdlib.h>
#define TORQ 3
#define TINS 3
#define TMUS 3
#define OCUPADO 0
#define LIBRE 1

typedef struct
{
    char nombre[20];
    char lugar[20];
    char tipo[20];
    int idOrquesta;
    int estado;
}eOrquesta;

typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;
    int idMusico;
    int idOrquesta;
    int idInstrumento;
    int estado;
}eMusico;

typedef struct
{
    char nombre[20];
    char tipo[20];
    int idInstrumento;
    int estado;
}eInstrumento;

int mostrarMenu(void);
int agregarOrquesta(eOrquesta[],int);
void inicializarArray(eOrquesta[],eInstrumento[],eMusico[]);
int buscarLibreOrquesta(eOrquesta[]);
void mostrarOrquestas(eOrquesta[]);
int agregarMusico(eMusico[],eOrquesta[],eInstrumento[]);
int buscarLibreMusico(eMusico[]);
int agregarInstrumento(eInstrumento[]);
void mostrarInstrumentos(eInstrumento[]);
int buscarLibreInstrumento(eInstrumento[]);
int eliminarOrquesta(eOrquesta[],eMusico[]);
int eliminarMusico(eMusico[],eInstrumento[]);
int modificarMusico(eMusico[],eInstrumento[]);
void mostrarMusicos(eMusico[],eInstrumento[]);
int getInt(char[]);
int validarEntero (char[]);



int main()
{

   int opcion;
   int retorno;
   eOrquesta orquestas[3]={{"Orquesta Sol","Salta","Sinfonica",1,OCUPADO},{"Orquesta Nahuel","La Rioja","Camara",2,OCUPADO},
                          {"Orquesta Algo","Cordoba","Filarmonica",3,OCUPADO}};
   eInstrumento instrumentos[3]={{"Guitarra","Cuerda",1,OCUPADO},{"Bateria","Percusion",2,OCUPADO},{"Flauta","Viento",3,OCUPADO}};
   eMusico musicos[3]={ {"Claudia","Barraza",50,1,1,2,OCUPADO},{"Benjamin","Aguirre",20,2,3,1,OCUPADO},{"Matias","Aguirre",25,3,2,3,OCUPADO} };

   //inicializarArray(orquestas,instrumentos,musicos);

   do
   {
       system("cls");
       opcion=mostrarMenu();

       switch(opcion)
       {
            case 1:
            retorno=agregarOrquesta(orquestas,TORQ);
            if(retorno)
            {
                printf("Se ingreso correctamente la orquesta.\n\n");
                system("pause");
            }
            else
            {
                printf("La operacion fue cancelada, reeingrese la orquesta.\n\n");
                system("pause");
            }
            break;
            case 2:
            system("cls");
            retorno=eliminarOrquesta(orquestas,musicos);
            if(retorno)
            {
                printf("Se elimino correctamente la orquesta.\n\n");
                system("pause");
            }
            else
            {
                printf("La operacion fue cancelada, reeingrese la orquesta.\n\n");
                system("pause");
            }
            break;
            case 3:
            system("cls");
            mostrarOrquestas(orquestas);
            break;
            case 4:
            retorno=agregarMusico(musicos,orquestas,instrumentos);
            if(retorno)
            {
                printf("Se ingreso correctamente el musico.\n\n");
                system("pause");
            }
            else
            {
                printf("La operacion fue cancelada, reeingrese el musico.\n\n");
                system("pause");
            }
            break;
            case 5:
            system("cls");
            retorno=modificarMusico(musicos,instrumentos);
             if(retorno)
            {
                printf("Se modifico correctamente el musico.\n\n");
                system("pause");
            }
            else
            {
                printf("La operacion fue cancelada, reeingrese el musico.\n\n");
                system("pause");
            }
            break;
            case 6:
            system("cls");
            retorno=eliminarMusico(musicos,instrumentos);
            if(retorno)
            {
                printf("Se elimino correctamente el musico.\n\n");
                system("pause");
            }
            else
            {
                printf("La operacion fue cancelada, reeingrese el musico.\n\n");
                system("pause");
            }
            break;
            case 7:
            system("cls");
            mostrarMusicos(musicos,instrumentos);
            break;
            case 8:
            retorno=agregarInstrumento(instrumentos);
            if(retorno)
            {
                printf("Se ingreso correctamente el instrumento.\n\n");
                system("pause");
            }
            else
            {
                printf("La operacion fue cancelada, reeingrese el instrumento.\n\n");
                system("pause");
            }


            break;
            case 9:
            system("cls");
            mostrarInstrumentos(instrumentos);
            break;
            case 10:
             printf("\n\nGracias por utilizar este programa!");
            break;
            default:
            while (opcion<1 || opcion>10)
            {
                printf("\n\nOpcion no valida, ingrese una opcion del 1 al 10\n\n");
                system("pause");
                break;
            }
            break;
       }

   }while(opcion!=10);

   return 0;
}


int mostrarMenu(void)
{
    char opcion[5];

    printf("1.Agregar orquesta.\n");
    printf("2.Elimar orquesta.\n");
    printf("3.Imprimir orquestas.\n");
    printf("4.Agregar musico.\n");
    printf("5.Modificar musico.\n");
    printf("6.Eliminar musico\n");
    printf("7.Imprimir musicos.\n");
    printf("8.Agregar instrumento.\n");
    printf("9.Imprimir instrumentos.\n");
    printf("10.SALIR.\n");

    printf("\n\n\nIngrese opcion: ");

    gets(opcion);

    getInt(opcion);



    return opcion;

}

void inicializarArray(eOrquesta orquestas[] ,eInstrumento instrumentos[],eMusico musicos[])
{
    int i;


   /* for(i=0;i<TORQ;i++)
    {
        orquestas[i].estado=LIBRE;
        orquestas[i].idOrquesta=i+1;
    }


    for(i=0;i<TINS;i++)
    {
        instrumentos[i].estado=LIBRE;
        instrumentos[i].idInstrumento=i+1;
    }*/

    for(i=0;i<TMUS;i++)
    {
        musicos[i].estado=LIBRE;
        musicos[i].idMusico=i+1;
    }

}
int agregarOrquesta(eOrquesta orquesta[] ,int sizeArray)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreOrquesta(orquesta);

    system("cls");

    if(posicionLibre!=-1)

    {
        printf("Ingrese nombre de la orquesta: ");
        fflush(stdin);
        gets(orquesta[posicionLibre].nombre);
        printf("\n\nIngrese lugar de la orquesta:");
        fflush(stdin);
        gets(orquesta[posicionLibre].lugar);
        printf("\nTipos de orquestas:Sinfonica/Filarmonica/Camara\n");
        printf("Ingrese tipo de orquesta: ");
        fflush(stdin);
        gets(orquesta[posicionLibre].tipo);

        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        scanf("%d",&confirmacion);

        if (confirmacion==1)
        {
            orquesta[posicionLibre].estado=OCUPADO;
            printf("\n\nEl ID UNICO de la orquesta es: %d \n\n", orquesta[posicionLibre].idOrquesta);
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }

}

int agregarMusico(eMusico musicos[],eOrquesta orquestas[],eInstrumento instrumentos[])
{
    int posicionLibre;
    int confirmacion;


    posicionLibre=buscarLibreMusico(musicos);

    system("cls");

    if(posicionLibre!=-1)

    {
        printf("Ingrese nombre de el musico: ");
        fflush(stdin);
        gets(musicos[posicionLibre].nombre);
        printf("\n\nIngrese el apellido del musico: ");
        fflush(stdin);
        gets(musicos[posicionLibre].apellido);
        printf("\n\nIngrese edad de el musico: ");
        scanf("%d",&musicos[posicionLibre].edad);

        system("cls");
        printf("Orquestas activas actualmente:\n ");
        mostrarOrquestas(orquestas);
        printf("\n\nIngrese ID de la orquesta a la cual pertence: ");
        scanf("%d",&musicos[posicionLibre].idOrquesta);

        system("cls");
        printf("Instrumentos activos actualmente:\n ");
        mostrarInstrumentos(instrumentos);
        printf("\n\nIngrese ID de el instrumento el cual toca: ");
        scanf("%d",&musicos[posicionLibre].idInstrumento);


        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        scanf("%d",&confirmacion);

        if (confirmacion==1)
        {
            musicos[posicionLibre].estado=OCUPADO;
            printf("El ID UNICO del musico es: %d",musicos[posicionLibre].idMusico);
            system("pause");
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }

}

int buscarLibreOrquesta(eOrquesta orquestas[])
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<TORQ;i++)
        {
            if(orquestas[i].estado==LIBRE)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;
}

void mostrarOrquestas(eOrquesta listaOrquestas[])
{
    int i;
    int orquestas=0;

    for(i=0;i<TORQ;i++)
    {
        if(listaOrquestas[i].estado==OCUPADO)
        {
            printf("Nombre de la orquesta: %s\n",listaOrquestas[i].nombre);
            printf("Lugar de la orquesta: %s\n",listaOrquestas[i].lugar);
            printf("Tipo de orquesta: %s\n",listaOrquestas[i].tipo);
            printf("ID UNICO de la orquesta: %d\n\n",listaOrquestas[i].idOrquesta);
            orquestas++;
        }

    }
    if(orquestas==0)
    {
        printf("No se encontraron orquestas cargadas.");
    }
    system("pause");
}

int buscarLibreMusico(eMusico listaMusicos[])
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<TMUS;i++)
        {
            if(listaMusicos[i].estado==LIBRE)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;

}
void mostrarInstrumentos(eInstrumento listaInstrumentos[])
{
    int i;
    int cantidadInstrumentos=0;

    for(i=0;i<TINS;i++)
    {
        if(listaInstrumentos[i].estado==OCUPADO)
        {
            printf("Nombre de el instrumento: %s\n",listaInstrumentos[i].nombre);
            printf("Tipo del instrumento: %s\n",listaInstrumentos[i].tipo);
            printf("ID UNICO del instrumento: %d\n\n",listaInstrumentos[i].idInstrumento);
            cantidadInstrumentos++;
        }

    }
    if(cantidadInstrumentos==0)
    {
        printf("No hay instrumentos cargados.");
    }
    system("pause");

}

void mostrarMusicos(eMusico listaMusicos[],eInstrumento listaInstrumentos[])
{
    int i;
    int j;
    int cantidadMusicos=0;

    for(i=0;i<TMUS;i++)
    {

        if(listaMusicos[i].estado==OCUPADO)
        {
            printf("Nombre y apellido del musico: %s %s\n",listaMusicos[i].nombre,listaMusicos[i].apellido);
            printf("ID de la orquesta en cual se desempeña: %d\n",listaMusicos[i].idOrquesta);
            printf("ID UNICO de el musico: %d\n",listaMusicos[i].idMusico);
            for(j=0;j<TINS;j++)
            {
                if(listaMusicos[i].idInstrumento==listaInstrumentos[j].idInstrumento)
                {
                     printf("Instrumento usado: %s\n",listaInstrumentos[j].nombre);
                     printf("Tipo de instrumento: %s\n\n",listaInstrumentos[j].tipo);
                     break;
                }
            }
            cantidadMusicos++;

        }

    }
    if(cantidadMusicos==0)
    {
        printf("No hay musicos cargados.");
    }
    system("pause");

}

int agregarInstrumento(eInstrumento instrumento[])
{
     int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreInstrumento(instrumento);

    system("cls");

    if(posicionLibre!=-1)

    {
        printf("Ingrese nombre de el instrumento: ");
        fflush(stdin);
        gets(instrumento[posicionLibre].nombre);
        printf("\n\nIngrese tipo de instrumento: ");
        fflush(stdin);
        gets(instrumento[posicionLibre].tipo);


        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        scanf("%d",&confirmacion);

        if (confirmacion==1)
        {
            instrumento[posicionLibre].estado=OCUPADO;
            printf("\n\nEl ID UNICO el instrumento es: %d \n\n", instrumento[posicionLibre].idInstrumento);
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }

}
int buscarLibreInstrumento(eInstrumento listaInstrumentos[])
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<TINS;i++)
        {
            if(listaInstrumentos[i].estado==LIBRE)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;

}

int eliminarOrquesta(eOrquesta listaOrquestas[],eMusico listaMusicos[])
{
    int idEliminar;
    int confirmacion;
    int retorno=0;

    printf("Lista de orquestas activas:\n\n");
    mostrarOrquestas(listaOrquestas);
    printf("\n\nIngrese id de la orquesta a eliminar: ");
    scanf("%d",&idEliminar);


    int i;
    int j;

    for(i=0;i<TORQ;i++)
    {
        if(listaOrquestas[i].idOrquesta==idEliminar)
        {
            printf("Orquesta encontrada, desea eliminar?\n");
            printf("Ingrese 1 para confirmar.\n");
            printf("Ingrese 2 para salir.\n\n");
            printf("Opcion elegida: ");
            scanf("%d",&confirmacion);

            if(confirmacion==1)
            {
                listaOrquestas[i].estado=LIBRE;
                for(j=0;j<TMUS;j++)
                {
                    if(listaOrquestas[i].idOrquesta==listaMusicos[j].idOrquesta)
                    {
                        listaMusicos[j].estado=LIBRE;
                    }
                }

            retorno=1;
            break;
            }
            else
            {
                retorno=0;
            }

        }
        else
        {
                printf("No se encontro el ID de la orquesta ingresada");
        }
    }
    return retorno;

}
int eliminarMusico(eMusico listaMusicos[],eInstrumento listaInstrumentos[])
{
    int idEliminar;
    int confirmacion;
    int retorno=0;

    printf("Lista de musicos activos:\n\n");
    mostrarMusicos(listaMusicos,listaInstrumentos);
    printf("\n\nIngrese id de el musico a eliminar: ");
    scanf("%d",&idEliminar);


    int i;


    for(i=0;i<TMUS;i++)
    {
        if(listaMusicos[i].idMusico==idEliminar)
        {
            printf("Musico encontrado, desea eliminar?\n");
            printf("Ingrese 1 para confirmar.\n");
            printf("Ingrese 2 para salir.\n\n");
            printf("Opcion elegida: ");
            scanf("%d",&confirmacion);

            if(confirmacion==1)
            {
                listaMusicos[i].estado=LIBRE;
            }
            else
            {
                retorno=0;
            }
        retorno=1;
        break;

        }
        else
        {
                printf("No se encontro el ID de la orquesta ingresada");
        }
    }
    return retorno;
}

int modificarMusico(eMusico listaMusicos[],eInstrumento listaInstrumentos[])
{
    int idModificar;
    int opcion;
    int confirmacion;
    int aux;
    int retorno=0;

    printf("Lista de musicos activos:\n\n");
    mostrarMusicos(listaMusicos,listaInstrumentos);
    printf("\n\nIngrese id de el musico a modificar: ");
    scanf("%d",&idModificar);


    int i;


    for(i=0;i<TMUS;i++)
    {
        if(listaMusicos[i].idMusico==idModificar)
        {
            printf("Musico encontrado, desea modificar?\n");
            printf("Ingrese 1 para modificar ID de la banda en que toca.\n");
            printf("Ingrese 2 para modificar edad.\n\n");
            printf("Opcion elegida: ");
            scanf("%d",&opcion);

            if(opcion==1)
            {
                printf("\nIngrese nuevo id de la banda en que toca: ");
                scanf("%d",&aux);
                printf("Confirma la modificacion?\n ");
                printf("Ingrese 1 para confirmar.\n");
                printf("Ingrese 2 para salir.\n\n");
                printf("Opcion elegida: ");
                scanf("%d",&confirmacion);

                if(confirmacion==1)
                {
                    listaMusicos[i].idOrquesta=aux;
                    retorno=1;
                }
                else
                {
                    retorno=0;
                }

            }
            else
            {
                printf("Ingrese edad: \n");
                scanf("%d",&aux);
                printf("Confirma la modificacion?\n");
                printf("Ingrese 1 para confirmar.\n");
                printf("Ingrese 2 para salir.\n\n");
                printf("Opcion elegida: ");
                scanf("%d",&confirmacion);

                if(confirmacion==1)
                {
                    listaMusicos[i].edad=aux;
                    retorno=1;
                }
                else
                {
                    retorno=0;
                }
            }
        retorno=1;
        break;
        }
        else
        {
                printf("No se encontro el ID de el musico ingresado.");
        }
    }
    return retorno;
}
int getInt(char* entero)
{
    int retorno;
    int enteroValidado;

    retorno=validarEntero(entero);

    while(retorno)
    {
        printf("Numero invalido.\n\n");
        printf("Reeingrese el numero: ");
        gets(entero);
        retorno=validarEntero(entero);
    }

    enteroValidado=atoi(entero);

    return enteroValidado;

}

int validarEntero (char* numeroValidar)
{
    int i;
    int lenght;
    int retorno=0;

    lenght=strlen(numeroValidar);

    if (lenght==0)  //VACIO
    {
        retorno=1;
    }

    for(i=0;i<lenght;i++)
    {

        if(isdigit(numeroValidar[i])==0) //0 NO ES NUMERO. !=0 ES NUMERO
        {
            retorno=1;
            break;
        }
    }

    return retorno;

}



