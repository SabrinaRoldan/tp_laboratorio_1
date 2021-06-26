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

/** \brief                      Realiza una suma entre dos n�meros enteros.
 *
 * \param                       Primer entero a sumar.
 * \param                       Segundo entero a sumar.
 * \return                      Retorna el resultado de la suma.
 *
 */
int operacionSuma (int num1, int num2);

/** \brief                      Realiza una resta entre dos n�meros enteros.
 *
 * \param                       Primer entero ingresado.
 * \param                       Entero a ser restado.
 * \return                      Retorna el resultado de la resta.
 *
 */
int operacionResta (int num1, int num2);

/** \brief                      Realiza una divisi�n entre dos n�meros enteros.
 *
 * \param                       Primer n�mero ingresado.
 * \param                       Segundo n�mero entero ingresado.
 * \return
 *
 */
float operacionDivision (int num1, int num2);

/** \brief                      Realiza una multiplicaci�n entre dos n�meros enteros.
 *
 * \param                       Primer n�mero a multiplicar.
 * \param                       Segundo n�mero a multiplicar.
 * \return                      Retorna el resultado de la multiplicaci�n.
 *
 */
int operacionMultiplicacion (int num1, int num2);

/** \brief                      Realiza la factorizaci�n de una numero
 *
 * \param                       N�mero ingresado a factorizar.
 * \return                      Retorna el resultado de la factorizaci�n del n�mero ingresado.
 *
 */
int operacionFactorizacion (int num1);

/** \brief                      Muestra por pantalla los n�meros elegidos para cada operando.
 *
 * \param flag1 int             Flag para mostrar el primero operando.
 * \param flag2 int             Flag para mostrar el segundo operando.
 * \param num1 int              Primer operando ingresado.
 * \param num2 int              Segundo operando ingresado.
 * \return void                 Muestra por pantalla el mensaje seg�n corresponda.
 *
 */
void mostrarOperandos(int flag1, int flag2, int num1, int num2);

/** \brief Muestra por consola los resultados de las operaciones y realiza validaciones.
 *
 * \param num1 int              Primer operando ingresado, se utiliza para validaci�n.
 * \param num2 int              Segundo operando ingresado, se utiliza para validaci�n.
 * \param suma int              Resultado de la operaci�n suma.
 * \param resta int             Resultado de la operaci�n resta.
 * \param division float        Resultado de la operaci�n divisi�n.
 * \param multiplicacion int    Resultado de la operaci�n multiplicaci�n.
 * \param factorial1 int        Resultado de la operaci�n factorial para el primer entero.
 * \param factorial2 int        Resultado de la operaci�n factorial para el segundo entero.
 * \return void                 Retorna por pantalla los mensajes correspondientes con los resultados de las operaciones.
 *
 */
void mostrarOperaciones(int num1,int num2,int suma, int resta, float division, int multiplicacion, int factorial1, int factorial2);

/** \brief                      Realiza una validaci�n sobre un flag.
 *
 * \param flag int              Flag ingresado.
 * \return int                  0 si el flag ya fue usado, o 1 si no se utiliz�.
 *
 */
int validacionFlag(int flag);

/** \brief                      Toma una cadena de caracteres, al analizarlo y �ste cumplir las condiciones
 *                              necesarias lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minimo int            M�nima cantidad de caracteres aceptado.
 * \param maximo int            M�xima cantidad de caracteres aceptado.
 * \param reintentos int*       Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param resultado char*       Puntero al espacio memoria donde se dejar� el resultado de la funci�n.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int* reintentos, char* resultado);

//unSignedInt
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y �ste
 *                              cumplir las condiciones necesarias de n�mero sin signo lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           M�nima cantidad de caracteres aceptado.
 * \param maxSize int           M�xima cantidad de caracteres aceptado.
 * \param minimo int            N�mero m�nimo aceptado.
 * \param maximo int            N�mero m�ximo aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input int*            Puntero al espacio memoria donde se dejar� el resultado de la funci�n.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getUnsignedInt(char* mensaje,char* mensajeError,int minSize,int maxSize,int minimo,int maximo,int reintentos,int* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un n�mero sin signo.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidNumber(char* stringRecibido);


//SignedInt
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y �ste
 *                              cumplir las condiciones necesarias de n�mero con signo lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           M�nima cantidad de caracteres aceptado.
 * \param maxSize int           M�xima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input int*            Puntero al espacio memoria donde se dejar� el resultado de la funci�n.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getSignedInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, int* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un n�mero con signo.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidSignedNumber(char* stringRecibido);

#endif /* ROLDAN_H_ */
