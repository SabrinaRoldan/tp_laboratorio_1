/*
 * roldan.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Usuario
 */

#ifndef ROLDAN_H_
#define ROLDAN_H_



/** \brief Realiza una suma entre dos números enteros.
 *
 * \param   Primer entero a sumar.
 * \param   Segundo entero a sumar.
 * \return  Retorna el resultado de la suma.
 *
 */
int operacionSuma (int num1, int num2);

/** \brief Realiza una resta entre dos números enteros.
 *
 * \param   Primer entero ingresado.
 * \param   Entero a ser restado.
 * \return  Retorna el resultado de la resta.
 *
 */
int operacionResta (int num1, int num2);

/** \brief Realiza una división entre dos números enteros.
 *
 * \param   Primer número ingresado.
 * \param   Segundo número entero ingresado.
 * \return
 *
 */
float operacionDivision (int num1, int num2);

/** \brief Realiza una multiplicación entre dos números enteros.
 *
 * \param   Primer número a multiplicar.
 * \param   Segundo número a multiplicar.
 * \return  Retorna el resultado de la multiplicación.
 *
 */
int operacionMultiplicacion (int num1, int num2);

/** \brief Realiza la factorización de una numero
 *
 * \param   Número ingresado a factorizar.
 * \return  Retorna el resultado de la factorización del número ingresado.
 *
 */
int operacionFactorizacion (int num1);

/** \brief Muestra por pantalla los números elegidos para cada operando.
 *
 * \param flag1 int Flag para mostrar el primero operando.
 * \param flag2 int Flag para mostrar el segundo operando.
 * \param num1 int  Primer operando ingresado.
 * \param num2 int  Segundo operando ingresado.
 * \return void     Muestra por pantalla el mensaje según corresponda.
 *
 */
void mostrarOperandos(int flag1, int flag2, int num1, int num2);

/** \brief Valida un número entero ingresado.
 *
 * \param pNum int*         Puntero a variable donde es ingresado el entero.
 * \param reintentos int    Reintentos permitidos en el ingreso del dato.
 * \param minimo int        Número mínimo permitido.
 * \param maximo int        Número máximo permitido.
 * \return int              Retorna 0 si se ejecutó, retorna 1 si no se ejecutó.
 *
 */
int getNumero(int* pNum,int reintentos, int minimo, int maximo);

/** \brief Muestra el menú de opciones por pantalla.
 *
 * \return void Retorna por medio de mensaje el menú de opciones.
 *
 */
void mostrarMenu();

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

/** \brief Realiza una validación sobre un flag.
 *
 * \param flag int  Flag ingresado.
 * \return int      Retorna 0 si el flag ya fue usado, o 1 si no se utilizó.
 *
 */
int validacionFlag(int flag);

#endif /* ROLDAN_H_ */
