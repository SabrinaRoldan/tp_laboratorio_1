/*
 * roldan.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Usuario
 */

#ifndef ROLDAN_H_
#define ROLDAN_H_


/** \brief                      Menu a mostrar que obtiene la opcion elegida por el usuario.
 *
 * \return                      Retorna la opcion seleccionada.
 *
 */
int menu();

/** \brief                      Realiza una suma entre dos números enteros.
 *
 * \param                       Primer entero a sumar.
 * \param                       Segundo entero a sumar.
 * \return                      Retorna el resultado de la suma.
 *
 */
int operacionSuma (int num1, int num2);

/** \brief                      Realiza una resta entre dos números enteros.
 *
 * \param                       Primer entero ingresado.
 * \param                       Entero a ser restado.
 * \return                      Retorna el resultado de la resta.
 *
 */
int operacionResta (int num1, int num2);

/** \brief                      Realiza una división entre dos números enteros.
 *
 * \param                       Primer número ingresado.
 * \param                       Segundo número entero ingresado.
 * \return
 *
 */
float operacionDivision (int num1, int num2);

/** \brief                      Realiza una multiplicación entre dos números enteros.
 *
 * \param                       Primer número a multiplicar.
 * \param                       Segundo número a multiplicar.
 * \return                      Retorna el resultado de la multiplicación.
 *
 */
int operacionMultiplicacion (int num1, int num2);

/** \brief                      Realiza la factorización de una numero
 *
 * \param                       Número ingresado a factorizar.
 * \return                      Retorna el resultado de la factorización del número ingresado.
 *
 */
int operacionFactorizacion (int num1);

/** \brief                      Muestra por pantalla los números elegidos para cada operando.
 *
 * \param flag1 int             Flag para mostrar el primero operando.
 * \param flag2 int             Flag para mostrar el segundo operando.
 * \param num1 int              Primer operando ingresado.
 * \param num2 int              Segundo operando ingresado.
 * \return void                 Muestra por pantalla el mensaje según corresponda.
 *
 */
void mostrarOperandos(int flag1, int flag2, int num1, int num2);

/** \brief Muestra por consola los resultados de las operaciones y realiza validaciones.
 *
 * \param num1 int              Primer operando ingresado, se utiliza para validación.
 * \param num2 int              Segundo operando ingresado, se utiliza para validación.
 * \param suma int              Resultado de la operación suma.
 * \param resta int             Resultado de la operación resta.
 * \param division float        Resultado de la operación división.
 * \param multiplicacion int    Resultado de la operación multiplicación.
 * \param factorial1 int        Resultado de la operación factorial para el primer entero.
 * \param factorial2 int        Resultado de la operación factorial para el segundo entero.
 * \return void                 Retorna por pantalla los mensajes correspondientes con los resultados de las operaciones.
 *
 */
void mostrarOperaciones(int num1,int num2,int suma, int resta, float division, int multiplicacion, int factorial1, int factorial2);

/** \brief                      Realiza una validación sobre un flag.
 *
 * \param flag int              Flag ingresado.
 * \return int                  0 si el flag ya fue usado, o 1 si no se utilizó.
 *
 */
int validacionFlag(int flag);

/** \brief                      Toma una cadena de caracteres, al analizarlo y éste cumplir las condiciones
 *                              necesarias lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minimo int            Mínima cantidad de caracteres aceptado.
 * \param maximo int            Máxima cantidad de caracteres aceptado.
 * \param reintentos int*       Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param resultado char*       Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int* reintentos, char* resultado);

//unSignedInt
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de número sin signo lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param minimo int            Número mínimo aceptado.
 * \param maximo int            Número máximo aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input int*            Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getUnsignedInt(char* mensaje,char* mensajeError,int minSize,int maxSize,int minimo,int maximo,int reintentos,int* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un número sin signo.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidNumber(char* stringRecibido);


//SignedInt
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de número con signo lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input int*            Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getSignedInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, int* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un número con signo.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidSignedNumber(char* stringRecibido);

#endif /* ROLDAN_H_ */
