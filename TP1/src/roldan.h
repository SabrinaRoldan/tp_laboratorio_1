/*
 * roldan.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Usuario
 */

#ifndef ROLDAN_H_
#define ROLDAN_H_



/** \brief Realiza una suma entre dos n�meros enteros.
 *
 * \param   Primer entero a sumar.
 * \param   Segundo entero a sumar.
 * \return  Retorna el resultado de la suma.
 *
 */
int operacionSuma (int num1, int num2);

/** \brief Realiza una resta entre dos n�meros enteros.
 *
 * \param   Primer entero ingresado.
 * \param   Entero a ser restado.
 * \return  Retorna el resultado de la resta.
 *
 */
int operacionResta (int num1, int num2);

/** \brief Realiza una divisi�n entre dos n�meros enteros.
 *
 * \param   Primer n�mero ingresado.
 * \param   Segundo n�mero entero ingresado.
 * \return
 *
 */
float operacionDivision (int num1, int num2);

/** \brief Realiza una multiplicaci�n entre dos n�meros enteros.
 *
 * \param   Primer n�mero a multiplicar.
 * \param   Segundo n�mero a multiplicar.
 * \return  Retorna el resultado de la multiplicaci�n.
 *
 */
int operacionMultiplicacion (int num1, int num2);

/** \brief Realiza la factorizaci�n de una numero
 *
 * \param   N�mero ingresado a factorizar.
 * \return  Retorna el resultado de la factorizaci�n del n�mero ingresado.
 *
 */
int operacionFactorizacion (int num1);

/** \brief Muestra por pantalla los n�meros elegidos para cada operando.
 *
 * \param flag1 int Flag para mostrar el primero operando.
 * \param flag2 int Flag para mostrar el segundo operando.
 * \param num1 int  Primer operando ingresado.
 * \param num2 int  Segundo operando ingresado.
 * \return void     Muestra por pantalla el mensaje seg�n corresponda.
 *
 */
void mostrarOperandos(int flag1, int flag2, int num1, int num2);

/** \brief Valida un n�mero entero ingresado.
 *
 * \param pNum int*         Puntero a variable donde es ingresado el entero.
 * \param reintentos int    Reintentos permitidos en el ingreso del dato.
 * \param minimo int        N�mero m�nimo permitido.
 * \param maximo int        N�mero m�ximo permitido.
 * \return int              Retorna 0 si se ejecut�, retorna 1 si no se ejecut�.
 *
 */
int getNumero(int* pNum,int reintentos, int minimo, int maximo);

/** \brief Muestra el men� de opciones por pantalla.
 *
 * \return void Retorna por medio de mensaje el men� de opciones.
 *
 */
void mostrarMenu();

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

/** \brief Realiza una validaci�n sobre un flag.
 *
 * \param flag int  Flag ingresado.
 * \return int      Retorna 0 si el flag ya fue usado, o 1 si no se utiliz�.
 *
 */
int validacionFlag(int flag);

#endif /* ROLDAN_H_ */
