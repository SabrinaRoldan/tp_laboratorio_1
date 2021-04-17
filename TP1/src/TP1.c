/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "roldan.h"
#define MINIMO 0
#define MAXIMO 100
#define REINTENTOS 5


int main(void) {

	setbuf(stdout,NULL);

    int     x;
    int     y;
    int     opcion;
    int     resultadoSuma;
    int     resultadoResta;
    float   resultadoDivision;
    int     resultadoMultiplicacion;
    int     resultadoFactorizacion1;
    int     resultadoFactorizacion2;
    int     flagPrimerOperando=0;
    int     flagSegundoOperando=0;
    int     flagOperaciones=0;

    do{
    mostrarMenu();

    mostrarOperandos(flagPrimerOperando,flagSegundoOperando,x,y);

    printf("Ingrese la opcion seleccionada: ");
    scanf("%d",&opcion);


    switch(opcion){
    case 1:
        getNumero(&x,REINTENTOS,MINIMO,MAXIMO);
        flagPrimerOperando=1;
        system("pause");
        break;
    case 2:
        getNumero(&y,REINTENTOS,MINIMO,MAXIMO);
        flagSegundoOperando=1;
        system("pause");
        break;
    case 3:
        if((!validacionFlag(flagPrimerOperando)) && (!validacionFlag(flagSegundoOperando))){
        resultadoSuma=operacionSuma(x,y);
        resultadoResta=operacionResta(x,y);
        resultadoDivision=operacionDivision(x,y);
        resultadoMultiplicacion=operacionMultiplicacion(x,y);
        resultadoFactorizacion1=operacionFactorizacion(x);
        resultadoFactorizacion2=operacionFactorizacion(y);
        flagOperaciones=1;
        }else{
            printf("Debe ingresar los dos operandos\n");
            }
        system("pause");
        break;
    case 4:
        if((validacionFlag(flagPrimerOperando)) && (validacionFlag(flagSegundoOperando))){
                    printf("Debe ingresar los dos operandos\n");
        }
        if(!validacionFlag(flagOperaciones)){
            mostrarOperaciones(x,y,resultadoSuma,resultadoResta,resultadoDivision
                               ,resultadoMultiplicacion,resultadoFactorizacion1
                               ,resultadoFactorizacion2);
            flagOperaciones=0;
            flagPrimerOperando=0;
            flagSegundoOperando=0;
        }else{
            printf("Debe ejecutar las operaciones para mostrar los resultados\n");
            }
        system("pause");
        break;
    case 5:
        break;
    default:
        printf("Ingrese una opcion valida\n");
        fflush(stdin);
        system("pause");
        break;

    }

    }while(opcion!=5);

    return 0;
}
