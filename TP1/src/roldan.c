/*
 * roldan.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include "roldan.h"


int getNumero(int *pNum,int reintentos,int minimo, int maximo){
    int num;
    int retorno;

    while(reintentos>0){
        printf("Ingrese un numero: ");
        scanf("%d",&num);
        if(num>=minimo && num<=maximo){
            *pNum=num;
            retorno=0;
            break;
            }else{
                printf("Error. Ingrese un numero valido\n");
                reintentos--;
            }
    }
    if(reintentos==0){
        retorno=1;
    }

    return retorno;
}

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
        resultado*=i;
    }

    return resultado;
}

void mostrarMenu(){
    system("cls");
    printf("***** Menu de opciones *****\n\n");
    printf("1- Ingresar primer operando (A)\n");
    printf("2- Ingresar segundo operando (B)\n");
    printf("3- Calcular todas las operaciones\n");
    printf("4- Informar resultados\n");
    printf("5- Salir\n\n");
}

void mostrarOperaciones(int num1,int num2,int suma, int resta, float division, int multiplicacion, int factorial1, int factorial2){
    printf("El resultado de A+B es: %d\n"  ,suma);
    printf("El resultado de A-B es: %d\n"  ,resta);

        if(num2==0){
            printf("No es posible dividir por cero\n");
        }else{
            printf("El resultado de A/B es: %.2f\n",division);
        }

        printf("El resultado de A*B es: %d\n"  ,multiplicacion);

        if(num1<0 || num2<0){
                printf("No es posible realizar el factorial de una numero negativo\n");
        }else{
            printf("El resultado de A! es: %d y de B! es: %d\n"  ,factorial1, factorial2);
            }
}

int validacionFlag(int flag){
    int retorno=0;

    if(flag!=1){
        retorno=1;
    }

    return retorno;
}
