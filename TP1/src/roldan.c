/*
 * roldan.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roldan.h"

void mostrarOperandos(int flag1, int flag2, int num1, int num2){

    if(flag1==0 && flag2==0)
    {
        printf("A=x B=y\n");
    }
    else if(flag1==1 && flag2==0)
    {
        printf("A=%d B=y\n",num1);
    }
    else if(flag1==0 && flag2==1)
    {
        printf("A=x B=%d\n",num2);
    }
    else
    {
        printf("A=%d B=%d\n",num1,num2);
    }
}

int operacionSuma (int num1, int num2){
    int resultado;

    resultado=num1+num2;

    return resultado;
}

int operacionResta (int num1, int num2){
    int resultado;

    resultado=num1-num2;

    return resultado;
}

float operacionDivision (int num1, int num2){
    float resultado;

    resultado=(float)num1/num2;

    return resultado;
}

int operacionMultiplicacion (int num1, int num2){
    int resultado;

    resultado=num1*num2;

    return resultado;
}

int operacionFactorizacion (int num1){
    int resultado=1;
    for(int i=1;i<=num1;i++){
        resultado=resultado*i;
    }

    return resultado;
}

int menu()
{
    int opcion;

    printf("\n\n***** Menu de opciones *****\n\n");
    printf("1- Ingresar primer operando (A)\n");
    printf("2- Ingresar segundo operando (B)\n");
    printf("3- Calcular todas las operaciones\n");
    printf("4- Informar resultados\n");
    printf("5- Salir\n\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void mostrarOperaciones(int num1,int num2,int suma, int resta, float division, int multiplicacion, int factorial1, int factorial2){
    printf("El resultado de %d+%d es: %d\n"  ,num1,num2,suma);
    printf("El resultado de %d-%d es: %d\n"  ,num1,num2,resta);

        if(num2==0){
            printf("No es posible dividir por cero\n");
        }else{
            printf("El resultado de %d/%d es: %.2f\n",num1,num2,division);
        }

        printf("El resultado de %d*%d es: %d\n"  ,num1,num2,multiplicacion);

        if(num1<0 || num2<0){
                printf("No es posible realizar el factorial de una numero negativo\n");
        }else{
            printf("El resultado de %d! es: %d y de %d! es: %d\n"  ,num1,factorial1,num2,factorial2);
            }
}

int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int* reintentos, char* resultado)
{
    int retorno=0;
    char bufferStr[maximo+10];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno=1;
                break;
            }
            printf("%s 1",mensajeError);
            (*reintentos)--;
        }while((*reintentos)>=0);
    }
    return retorno;
}

int validacionFlag(int flag){
    int retorno=0;

    if(flag!=1){
        retorno=1;
    }

    return retorno;
}

//unSignedInt
int utn_getUnsignedInt(char* mensaje,char* mensajeError,int minSize,int maxSize,int minimo,int maximo,int reintentos,int* input)
{
    int retorno=0;
    int aux;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && maximo>=minimo && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr) && isValidNumber(bufferStr)==1)
            {
                aux=atoi(bufferStr);
                if (aux>=minimo && aux<=maximo)
                {
                    *input=aux;
                    retorno=1;
                    break;
                }
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//SignedInt
int utn_getSignedInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, int* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr) && isValidSignedNumber(bufferStr)==1)
            {
                *input=atoi(bufferStr);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidSignedNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='+' && stringRecibido[0]!='-'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
