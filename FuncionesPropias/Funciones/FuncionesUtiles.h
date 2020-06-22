/** \brief Muestra menu de opciones.
 *
 * \param char[] Valor de primer operando.
 * \param char[] Valor de segundo operando.
 * \return int   Opcion elegida por el usuario.
 *
 */
int mostrarMenuCalculadora(char[] ,char[]);
//ABM


/** \brief Muestra menu de ABB
 *
 * \param void
 * \return int Opcion elegida por el usuario.
 *
 */
int mostrarMenuABM(void);



/** \brief Cargar campos predeterminado para pruebas
 *
 * \param ARRAY
 * \param LARGO ARRAY
 * \return void
 *
 */
void hardcodearEmpleado(Employee nominaEmpleados[],int sizeEmpleados);



/** \brief Inicializa estructura con ID autoincrementable y estado.
 *
 * \param ARRAY
 * \param LARGO ARRAY
 * \return void
 *
 */
void initEmployees(Employee nominaEmpleados[],int sizeEmpleados);



/** \brief Alta de empleado
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param sizeEmpleados int LARGO ARRAY
 * \return int 1 ALTA CORRECTA, 0 Alta cancelada.
 *
 */
int addEmployees(Employee nominaEmpleados[],int sizeEmpleados);



/** \brief Busca empleado por id para su posterior modificacion
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param sizeEmpleados int LARGO ARRAY
 * \param idModificar int ID A BUSCAR Y MODIFICAR
 * \return int 1 MODIFICACION CORRECTA, 0 MODIFICACION CANCELADA.
 *
 */
int findEmployeeById(Employee nominaEmpleados[],int sizeEmpleados,int idModificar);



/** \brief MUESTRA MENU PARA ELECCION DE CAMPOS A MODIFICAR
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param posicionModificar int LARGO ARRAY
 * \return int POSICION DEL ARRAY A MODIFICAR
 *
 */
int menuModificaciones(Employee nominaEmpleados[],int posicionModificar);



/** \brief BAJA EMPLEADO
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param sizeEmpleados int LARGO ARRAY
 * \param idEliminar int ID DEL EMPLEADO A ELIMINAR
 * \return int 1 BAJA CORRECTA,0 BAJA CANCELADA
 *
 */
int removeEmployee(Employee nominaEmpleados[],int sizeEmpleados,int idEliminar);



/** \brief MUESTRA LISTA DE EMPLEADOS CON SUELDO TOTAL Y PROMEDIO
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param sizeEmpleados int LARGO ARRAY
 * \return void
 *
 */
void mostrarEmpleados(Employee nominaEmpleados[],int sizeEmpleados);



/** \brief MUESTRA EMPLEADOS CON SUELDO POR ENCIMA DEL PROMEDIO.
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param sizeEmpleados int LARGO ARRAY
 * \param sueldoPromedio float SUELDO PROMEDIO
 * \return void
 *
 */
void mostrarEmpleadosEncimaPromedio(Employee nominaEmpleados[] ,int sizeEmpleados,float sueldoPromedio);



/** \brief CARGAR CAMPOS CORRESPONDIENTES A LA ESTRUCTURA
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param posicionLibre int POSICION DEL ARRAY A TRATAR
 * \return int 1 CONFIRMACION, 0 CANCELA OPERACION
 *
 */
int cargarCamposEmpleados(Employee nominaEmpleados[],int posicionLibre);



/** \brief BUSCAR ESPACIO LIBRE EN ARRAY
 *
 * \param nominaEmpleados[] Employee ARRAY
 * \param sizeEmpleados int LARGO ARRAY
 * \return int POSICION LIBRE
 *
 */
int buscarLibreArray(Employee nominaEmpleados[],int sizeEmpleados );



/** \brief ORDENA ARRAY DE ESTRUCTURA POR NOMBRE Y PROMEDIO
 *
 * \param listado[] eAlumno ARRAY
 * \param tam int LARGO ARRAY
 * \return void
 *
 */
void ordenarListadoDeAlumnosPorNombreYporPromedio(eAlumno listado[], int tam);
//VALIDACIONES

/** \brief Ingresa una cadena con la opcion ingresada del usuario para su posterior validacion.
 *
 * \param char[] Cadena ingresada por el usuario.
 * \return int Numero validado.
 *
 */


/** \brief
 *
 * \param listaProductos[] eProducto
 * \param sizeProd int
 * \param listaProveedor[] eProveedor
 * \param sizeProv int
 * \return void
 *
 */
void mostrarProvConSusProductos(eProducto listaProductos[],int sizeProd,eProveedor listaProveedor[],int sizeProv);



/** \brief
 *
 * \param listaProductos[] eProducto
 * \param sizeProducto int
 * \param listaProveedores[] eProveedor
 * \param sizeProveedor int
 * \return void
 *
 */
void proveedorMasProductos(eProducto listaProductos[],int sizeProducto,eProveedor listaProveedores[],int sizeProveedor);





int getInt(char[]);


/** \brief Analisis de una cadena para determinar que sea numerica.
 *
 * \param char[] Cadena a analizar.
 * \return 0 si la cadena es numerica, 0 si no es numerica.
 *
 */
 int validarEntero (char[]);



/** \brief Ingresa una cadena con la opcion ingresada del usuario para su posterior validacion.
 *
 * \param char[] Cadena ingresada por el usuario.
 * \return float Numero validado.
 *
 */
float getFloat(char[]);



/** \brief Analisis de una cadena para determinar que sea flotante.
 *
 * \param char[] Cadena a analizar.
 * \return int 0 si la cadena es numero flotante, 0 si no es numerica.
 *
 */
int validarFloat(char[]);



/** \brief Ingresa un caracter escrito por el usuario para su posterior validacion.
 *
 * \param char Caracter ingresado por el usuario.
 * \return char Caracter validado.
 *
 */
char getChar(char);



/** \brief Analisis de una cadena para determinar que sea un caracter valido.
 *
 * \param char Caracter a validar
 * \return 0 si es valido, 1 si es invalido.
 *
 */
int validarChar (char);



/** \brief Ordenamiento de un vector numerico
 *
 * \param  Vector numerico a ordenar.
 *
 */
void ordenarVectorNumerico (int[]);



/** \brief Compara string numerico con una cadena constante VER PORQUE NO FUNCIONA.
 *
 * \param char[] String a comparar.
 * \param char[] const String para comparacion.
 * \return int 1 si son iguales, 0 no son iguales.
 *
 */
int compararString(char[],const char[]);



/** \brief Valida que una cadena contenga solo caracteres validos.
 *
 * \param char[] Cadena a validar
 * \return int 1 la cadena es valida, 0 la cadena no es valida.
 *
 */
int validarCadena(char[]);



/** \brief Validacion de un numero entre un rango minimo y maximo.
 *
 * \param entrada[] char Numero a validar.
 * \param rangoMinimo int Rango minimo para la validacion.
 * \param rangoMaximo int Rango maximo para la validacion.
 * \return int Numero validado.
 *
 */
int validarIntEntreRangos(char entrada[] ,int rangoMinimo,int rangoMaximo);



/** \brief Formatea un nombre y apellido al siguiente formato: Aguirre, Matias.
 *
 * \param Nombre
 * \param Apellido
 *
 */
void formatearNombres (char* nombre,char* apellido);



/** \brief Verifica que un array tenga algun elemento activo
 *
 * \param Array
 * \param Largo array
 * \return int 1 cargado,0 vacio
 *
 */
int verificarArrayCarga(Employee nominaEmpleados[],int sizeEmpleados);

