#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//MENU

int mostrarMenuCalculadora(char* numeroMenuX ,char* numeroMenuY)
{

        int opcion;

        printf("BIENVENIDOS A LA CALCULADORA!!\n\n");
        printf("1. Ingresar 1er operando (A=%s)",numeroMenuX);
        printf("\n2. Ingresar 2do operando (B=%s)", numeroMenuY);
        printf("\n3. Calcular todas las operaciones.");
        printf("\n  A). Calcular la suma (A+B)");
        printf("\n  B). Calcular la resta (A-B)");
        printf("\n  C). Calcular la division (A/B)");
        printf("\n  D). Calcular la multiplicacion (A*B)");
        printf("\n  E). Calcular el factorial (A!)");
        printf("\n4. Informar resultados.");
        printf("\n  A). El resultado de A+B es:");
        printf("\n  B). El resultado de A-B es:");
        printf("\n  C). El resultado de A/B es:");
        printf("\n  D). El resultado de A/B es:");
        printf("\n  E). El factorial de A es: y El factorial de B es: ");
        printf("\n5. Salir");

        printf("\n\nOpcion elegida:");
        scanf("%d",& opcion);
        system("cls");
        return opcion;

}

int mostrarMenuABM(void)
{
        char entrada[10];
        int opcion;


        printf("BIENVENIDOS: \n\n");
        printf("1. Alta empleado. ");
        printf("\n2. Modificar empleado. ");
        printf("\n3. Baje empleado. ");
        printf("\n4. Informar empleados y salarios.");
        printf("\n5. Salir.");

        printf("\n\nOpcion elegida:");
        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,5);
        system("cls");
        return opcion;


}

//ABM

void hardcodearEmpleado(Employee nominaEmpleados[],int sizeEmpleados)
{
    int id[5]={1,2,3,4,5} ;
    char name[5][51]= {"Matias","Mauro","Claudia","Benjamin","Anastasia"};
    char lastName[5][51]= {"Aguirre","Campos","Barraza","Aguirre","Anido"};
    float salary[5]={10000,15000,20000,25000,30000};
    int sector[5]={1,1,2,2,3} ;
    int isEmpty[5]={true,false,false,false,false};
    int i;

    for(i=0;i<sizeEmpleados;i++)
    {
        nominaEmpleados[i].id=id[i];
        strcpy(nominaEmpleados[i].name,name[i]);
        strcpy(nominaEmpleados[i].lastName,lastName[i]);
        nominaEmpleados[i].salary=salary[i];
        nominaEmpleados[i].sector=sector[i];
        nominaEmpleados[i].isEmpty=isEmpty[i];
    }


}
void initEmployees(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;

    for(i=0;i<sizeEmpleados;i++)
    {
        nominaEmpleados[i].id=i+1;
        nominaEmpleados[i].isEmpty=true;
    }

}

int addEmployees(Employee nominaEmpleados[],int sizeEmpleados)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreEmpleados(nominaEmpleados,sizeEmpleados);

    system("cls");

    if(posicionLibre!=-1)

    {
        confirmacion=cargarCamposEmpleados(nominaEmpleados,posicionLibre);


        if (confirmacion==1)
        {
            nominaEmpleados[posicionLibre].isEmpty=false;
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

int findEmployeeById(Employee nominaEmpleados[],int sizeEmpleados,int idModificar)
{
    int i;
    int retorno=0;
    int contEmpleados=0;



    if(idModificar<0 || idModificar>sizeEmpleados)
    {
        return 0;
    }

    for(i=0;i<sizeEmpleados;i++)

    {
        if((nominaEmpleados[i].id==idModificar) && (nominaEmpleados[i].isEmpty==false))
        {
            printf("EMPLEADO ENCONTRADO. \n");

            contEmpleados++;
            retorno=menuModificaciones(nominaEmpleados,i);

        }

    }

    if(contEmpleados==0)
    {
        printf("No se encontraron empleados\n\n");

    }

    return retorno;


}

int menuModificaciones(Employee nominaEmpleados[],int posicionModificar)
{
    char entrada[10];
    int opcion;
    int confirmacion;
    float nuevoSalario;
    int nuevoSector;
    char auxModificacion[30];


        printf("\n\n1.Modificar nombre.");
        printf("\n2.Modificar apellido.");
        printf("\n3.Modificar salario.");
        printf("\n4.Modificar sector.");
        printf("\n\nIngrese opcion: ");

        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,4);

                switch(opcion)
                {
                    case 1:
                    system("cls");
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Nombre invalido, reeingrese nombre: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,4);

                    if (confirmacion==1)
                    {
                        strcpy(nominaEmpleados[posicionModificar].name,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 2:
                    system("cls");
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Apellido invalido, reeingrese apellido: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,4);

                    if (confirmacion==1)
                    {
                        strcpy(nominaEmpleados[posicionModificar].lastName,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 3:
                     system("cls");
                    printf("Ingrese nuevo salario: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevoSalario=getFloat(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,4);

                    if (confirmacion==1)
                    {
                        nominaEmpleados[posicionModificar].salary=nuevoSalario;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 4:
                    system("cls");
                    printf("Ingrese nuevo sector: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevoSector=getInt(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,4);

                    if (confirmacion==1)
                    {
                        nominaEmpleados[posicionModificar].sector=nuevoSector;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;
                    default:
                    system("cls");
                    printf("Opcion invalida, vuelva a comenzar.\n\n");
                    system("pause");
                    return 0;
                    break;
                }
}

int removeEmployee(Employee nominaEmpleados[],int sizeEmpleados,int idEliminar)
{
    int i;
    char entrada[10];
    int confirmacion;
    int retorno=0;
    int contEmpleados=0;

    for(i=0;i<sizeEmpleados;i++)

    {
        if((nominaEmpleados[i].id==idEliminar) && (nominaEmpleados[i].isEmpty==false))
        {
                contEmpleados++;
                printf("EMPLEADO ENCONTRADO. \n");

                printf("Ingrese 1 para confirmar la eliminacion.\n");
                printf("Ingrese 2 para salir.\n\n");
                printf("Opcion elegida: ");

                gets(entrada);

                confirmacion=validarIntEntreRangos(entrada,1,2);

                if (confirmacion==1)
                {
                    nominaEmpleados[i].isEmpty=true;
                    return 1;
                }
                else
                {
                    return 0;
                }
                break;
        }

    }

    if(contEmpleados==0)
    {
        printf("No se encontraron empleados\n\n");

    }


    return retorno;



}

void mostrarEmpleados(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;
    float totalSalarios=0;
    int contEmpleados=0;
    float promedio;

    printf("ID      NOMBRE          APELLIDO  SALARIO           SECTOR \n");

    for(i=0;i<sizeEmpleados;i++)
    {
        if(nominaEmpleados[i].isEmpty==false)
        {


            printf("%d\t",nominaEmpleados[i].id);
            printf("%s     \t",nominaEmpleados[i].name);
            printf("%s\t  ",nominaEmpleados[i].lastName);
            printf("%.2f\t    ",nominaEmpleados[i].salary);
            printf("%d\n",nominaEmpleados[i].sector);
            totalSalarios=nominaEmpleados[i].salary+totalSalarios;
            contEmpleados++;

        }
    }
    printf("\nSalario total todos los empleados: %.2f\n",totalSalarios);
    promedio=totalSalarios/contEmpleados;
    printf("Promedio de salario: %.2f\n\n",promedio);
    mostrarEmpleadosEncimaPromedio(nominaEmpleados,sizeEmpleados,promedio);

    printf("\n\n");
    system("pause");
}

void mostrarEmpleadosEncimaPromedio(Employee nominaEmpleados[] ,int sizeEmpleados,float sueldoPromedio)
{
    int i;

    printf("Empleados con sueldo mayor al promedio: \n");

    for(i=0;i<sizeEmpleados;i++)
    {
        if(nominaEmpleados[i].isEmpty==false && nominaEmpleados[i].salary>sueldoPromedio)
        {


            printf("%d\t",nominaEmpleados[i].id);
            printf("%s     \t",nominaEmpleados[i].name);
            printf("%s\t  ",nominaEmpleados[i].lastName);
            printf("%.2f\t    ",nominaEmpleados[i].salary);
            printf("%d\n",nominaEmpleados[i].sector);

        }
    }
}

int cargarCamposEmpleados(Employee nominaEmpleados[],int posicionLibre)
{
    char entrada[10];
    char opcion[5];
    int confirmacion;


        printf("Ingrese nombre del empleado: ");
        fflush(stdin);
        gets(nominaEmpleados[posicionLibre].name);
        while(validarCadena(nominaEmpleados[posicionLibre].name)==0)
        {
            system("cls");
            printf("Nombre invalido, reeingrese nombre: ");
            gets(nominaEmpleados[posicionLibre].name);
            validarCadena(nominaEmpleados[posicionLibre].name);

        }
        printf("\nIngrese apellido del empleado: ");
        fflush(stdin);
        gets(nominaEmpleados[posicionLibre].lastName);
        while(validarCadena(nominaEmpleados[posicionLibre].lastName)==0)
        {
            system("cls");
            printf("Apellido invalido, reeingrese apellido: ");
            gets(nominaEmpleados[posicionLibre].lastName);
            validarCadena(nominaEmpleados[posicionLibre].lastName);

        }
        printf("\nIngrese salario del empleado: ");
        gets(entrada);
        nominaEmpleados[posicionLibre].salary=getFloat(entrada);

        printf("\nIngrese sector del empleado: ");
        gets(entrada);
        nominaEmpleados[posicionLibre].sector=getInt(entrada);

        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(opcion);

        confirmacion=validarIntEntreRangos(opcion,1,2);

        return confirmacion;

}


int buscarLibreArray(Employee nominaEmpleados[],int sizeEmpleados )
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<sizeEmpleados;i++)
        {
            if(nominaEmpleados[i].isEmpty==true)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;
}

void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam)
{
     int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
               auxAlumno  =  listado[i];
               listado[i] = listado[j];
               listado[j] = auxAlumno;
            }
            else
            {
               if(strcmp(listado[i].nombre,listado[j].nombre)==0)
               {
                   if(listado[i].promedio>listado[j].promedio)
                   {
                          auxAlumno  =  listado[i];
                          listado[i] = listado[j];
                          listado[j] = auxAlumno;
                   }
               }
            }

        }
    }
}

void mostrarProvConSusProductos(eProducto listaProductos[],int sizeProd,eProveedor listaProveedor[],int sizeProv)
{
    int i;
    int j;
    int contProductos;

    for(i=0;i<4;i++)
    {
        printf("\nProvedor: %s",listaProveedor[i].nombre);
        contProductos=0;

        for(j=0;j<10;j++)
        {

            if(listaProveedor[i].id==listaProductos[j].IdProv && listaProductos[j].estado==1)
            {
                printf("\n%s---%.2f---%d",listaProductos[j].nombre,listaProductos[j].precio,listaProductos[j].stock);
                contProductos++;
            }
        }

        if(contProductos==0)
        {
            printf("\nNo tiene producto.");
        }
    }

}


void proveedorMasProductos(eProducto listaProductos[],int sizeProducto,eProveedor listaProveedores[],int sizeProveedor)
{
    eAux auxProvProd[4];
    int i;
    int j;
    int maximo=0;

    for(i=0; i<sizeProveedor; i++)
    {
        auxProvProd[i].idProveedor = listaProveedores[i].id;
        auxProvProd[i].cantProductos = 0;
    }

     for(i=0; i<sizeProveedor; i++)//
    {
        for(j=0; j<sizeProducto; j++)
        {
            if(auxProvProd[i].idProveedor == listaProductos[j].IdProv && listaProductos[j].estado==1)
            {
                auxProvProd[i].cantProductos++;
            }
        }
    }

    for(i=0; i<sizeProveedor; i++)
    {
        if(i==0 || auxProvProd[i].cantProductos>maximo)
        {
            maximo = auxProvProd[i].cantProductos;
        }
    }

    printf("\n\nMAXIMO\n");

    for(i=0; i<sizeProveedor; i++)
    {

            if(listaProveedores[i].id == auxProvProd[i].idProveedor && auxProvProd[i].cantProductos == maximo)
            {


                printf("\n%s-----%d", listaProveedores[i].nombre,auxProvProd[i].cantProductos);

            }

    }



}


//VALIDACIONES

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

float getFloat(char* numeroValidar)
{

   float operandoValidado;

    while(validarFloat(numeroValidar)==1)
    {
        system("color 40");
        printf("Numero no valido!!, Ingrese otro numero: ");
        fflush(stdin);
        gets(numeroValidar);
        validarFloat(numeroValidar);

    }
    system("color 0F");

    operandoValidado=atof(numeroValidar);

    return operandoValidado;

}
int validarFloat(char* numeroValidar )
{

     int i;
     float numero;
     int lenght;
     int contadorPuntos=0;
     lenght=strlen(numeroValidar);

     numero=atof(numeroValidar);

     if(numero==0)
     {
        return 1;
     }

     if(numeroValidar[0]=='\0')
        return 1;


     for (i=0;i<lenght;i++)
    {


              if(isdigit(numeroValidar[i])==0 || isspace(numeroValidar[i]!=0)) //SI ES 0 ES UN DIGITO INVALIDO (NO ES NUMERO)
            {

              if(numeroValidar[i]!='-' && numeroValidar[i]!='.')
                return 1;

              //SIGNO -
              if(numeroValidar[i]=='-')
              {
                  if( lenght==1 || i!=0 )
                  return 1;
              }
              //SIGNO .
               if(numeroValidar[i]=='.')
                   if(i==0)
                   return 1;
               else
                   contadorPuntos++;

               if(contadorPuntos>1)
                    return 1;

            }


    }
    return 0;

}

char getChar(char letraValidar)
{
    char letraValidada;

    while(validarChar(letraValidar)==1)
    {
        printf("Letra invalida, ingrese otra letra: ");
        fflush(stdin);
        scanf("%c",&letraValidar);
        validarChar(letraValidar);

    }


    return letraValidada;
}

int validarChar(char letraValidar)
{
    int retorno=0;

    if( (letraValidar>='a' && letraValidar<='z') || (letraValidar>='A' && letraValidar<='Z') )
        retorno=0;
    else
        retorno=1;

    return retorno;

}

void ordenarVectorNumerico (int vector[])
{
    int i;
    int j;
    int aux;

    for(i=0;i<4-1;i++)
    {
        //if(vector[i]==-1);
        //   continue; Corta el for y pasa a la siguiente iteracion.
        for(j=i+1;j<4;j++)
        {
            if((vector[i]!=-1 && vector[j]!=-1) && vector[i]>vector[j]) //(vector[i]!=-1 && vector[j]!=-1) PARA OBVIAR LOS CARGADOS CON -1 (VACIOS)
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }

    for(i=0;i<4;i++)
    {
        printf("%d\n",vector[i]);
    }
}

int compararString(char* entrada,const char* comparacion)
{
    int sizeEntrada;
    int sizeComparacion;
    int aux;

    strupr(entrada);
    strupr(comparacion);

    sizeEntrada=strlen(entrada);
    sizeComparacion=strlen(comparacion);

    if(sizeEntrada==sizeComparacion)
    {
        aux=strcmp(entrada,comparacion);
        if(aux==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int validarCadena(char cadenaValidar[])
{
    int retorno=0;
    int lenght;
    int i;
    int contadorEspacios=0;

    lenght=strlen(cadenaValidar);

    for(i=0;i<lenght;i++)
    {
        if(cadenaValidar[i]==' ')
        {
            contadorEspacios++;
        }

        if( (cadenaValidar[i]>='a' && cadenaValidar[i]<='z') || (cadenaValidar[i]>='A' && cadenaValidar[i]<='Z') || (contadorEspacios==1))
        {
             retorno=1;
        }
        else
        {
            retorno=0;
            break;
        }

    }


    return retorno;


}

int validarIntEntreRangos(char entrada[] ,int rangoMinimo,int rangoMaximo)
{
    int numeroValidar;

    numeroValidar=getInt(entrada);

    while(numeroValidar<rangoMinimo || numeroValidar>rangoMaximo)
    {
      //  system("cls");
        printf("Numero invalido, reeingrese un numero valido: \n");
     //   printf("1.Confirma.\n");
     //   printf("2.Cancela.\n\n");
        printf("Ingrese opcion:");
        gets(entrada);
        numeroValidar=getInt(entrada);

    }

    return numeroValidar;

}



void formatearNombres (char* nombre,char* apellido)
{
    char apellidoNombre[30];
    int i;

    strlwr(nombre);
    strlwr(apellido);
    nombre[0]=toupper(nombre[0]);
    apellido[0]=toupper(apellido[0]);

    for(i=0;i<strlen(nombre);i++)
    {
        if(isspace(nombre[i]))
            nombre[i+1]=toupper(nombre[i+1]);
    }

    strcpy(apellidoNombre, apellido);
    strcat(apellidoNombre, ", ");
    strcat(apellidoNombre, nombre);

    printf("%s", apellidoNombre);

}
int verificarArrayCarga(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;
    int retorno=0;

    for(i=0;i<sizeEmpleados;i++)
    {
        if(nominaEmpleados[i].isEmpty==false)
        {
            return 1;
        }
        else
        {
            continue;
        }
    }

    return retorno;
}
