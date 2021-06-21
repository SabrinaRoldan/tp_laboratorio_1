#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo datos.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo datos.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option=0;
    int proximoId=0;
    int flagDatosTexto=0;
    int flagDatosBinario=0;
    int flagIdTexto=0;
    int flagIdBinario=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menu(&option))
        {
            case 1:
                if(flagIdTexto)
                {
                    proximoId=proximoId-1;
                }

                if(!flagDatosTexto)
                {
                    if(controller_loadFromText("data.csv",listaEmpleados,&proximoId))
                    {
                    printf("Se ha cargado el archivo de texto con exito!!\n");
                    flagDatosTexto=1;
                    }
                    else
                    {
                        printf("Error al cargar el archivo de texto\n");
                    }
                }
                else
                {
                    printf("Los datos ya han sido cargados previamente desde este archivo \n");
                }
                break;

            case 2:
                if(flagIdBinario)
                {
                    proximoId=proximoId-1;
                }

                if(!flagDatosBinario)
                {
                    if(controller_loadFromBinary("datos.bin",listaEmpleados,&proximoId))
                    {
                    printf("Se ha cargado el archivo binario con exito!!\n");
                    flagDatosBinario=1;
                    }
                    else
                    {
                        printf("Error al cargar el archivo binario\n");
                    }
                }
                else
                {
                    printf("Los datos ya han sido cargados previamente desde este archivo.\n");
                }
                break;

            case 3:
                if(!controller_addEmployee(listaEmpleados,&proximoId))
                {
                    printf("Ha ocurrido un error al dar de alta a un empleado\n");
                }
                else
                {
                    printf("Alta de empleado exitosa!\n");
                    flagIdTexto=1;
                    flagIdBinario=1;
                }
                break;

            case 4:
                controller_editEmployee(listaEmpleados);
                break;

            case 5:
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("Error al dar de baja al empleado\n");
                }
                else
                {
                    printf("Baja exitosa!\n");
                }
                break;

            case 6:
                if(ll_len(listaEmpleados)==0)
                {
                    printf("No hay empleados cargados al sistema\n");
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                }
                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                break;

            case 8:
                if(!controller_saveAsText("datos2.csv",listaEmpleados))
                {
                    printf("Error al guardar el archivo de texto\n");
                }
                else
                {
                    printf("El archivo de texto se ha guardado con exito!\n\n");
                }
                break;

            case 9:
                if(!controller_saveAsBinary("datos.bin",listaEmpleados))
                {
                    printf("Error al guardar el archivo binario\n");
                }
                else
                {
                    printf("El archivo binario se ha guardado con exito!\n\n");
                }
                break;

            case 10:
                printf("Ha salido del programa.\nHasta la proxima!!!\n\n");
                break;

            default:
                printf("Opcion no valida\n");
                fflush(stdin);
                break;
        }
        system("pause");

    }while(option != 10);

    return 0;
}

