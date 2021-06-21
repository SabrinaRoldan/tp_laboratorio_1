#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,int* proximoId)
{
    int retorno=0;
    int cant;
    int nuevoId;
    char buffer[4][128];

    Employee* empleado=employee_new();
    if(pFile==NULL)
        {
            printf("No se pudo cargar el archivo\n");
        }

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        do
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant<3)
            {
                printf("Error al cargar el archivo.\n");
                break;
            }

            empleado=employee_newParametros(itoa((atoi(buffer[0])+(*proximoId)),buffer[0],10),buffer[1],buffer[2],buffer[3]);

            if(empleado==NULL)
            {
                printf("Error al cargar el empleado.\n");
            }
            else
            {
                ll_add(pArrayListEmployee,empleado);
                retorno=1;
            }


        }while(!feof(pFile));

        nuevoId=atoi(buffer[0])+(*proximoId);
        *proximoId=nuevoId;
        (*proximoId)++;
        return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,int* proximoId)
{
    int cant;
    int retorno=0;
    int nuevoId;

    if(pFile==NULL)
    {
        printf("No se pudo abrir  el archivo\n");
    }

    while(!feof(pFile))
    {
        Employee* empleado=employee_new();
        if(empleado!=NULL)
        {
            //empleado->id=empleado->id+(*proximoId);
            cant=fread(empleado,sizeof(Employee),1,pFile);

            if(cant<1)
            {
                break;
            }
            ll_add(pArrayListEmployee,empleado);
            empleado->id=empleado->id+(*proximoId);
            nuevoId=empleado->id;
            empleado=NULL;
            retorno=1;
        }
    }

    *proximoId=nuevoId;
    (*proximoId)++;


    return retorno;
}
