#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "roldan.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int* proximoId)
{
    int retorno=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* f=fopen(path,"r");
        if(parser_EmployeeFromText(f,pArrayListEmployee,proximoId))
        {
            retorno=1;
            fclose(f);
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int* proximoId)
{
    int retorno=0;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* f=fopen(path,"rb");
        if(parser_EmployeeFromBinary(f,pArrayListEmployee,proximoId))
        {
            retorno=1;
            fclose(f);
        }
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int retorno=0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int id;

    Employee* auxEmpleado=employee_new();

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>=0)
    {
        system("cls");
        printf("        Alta Empleado\n\n");

        if(*pId==0)
        {
            *pId=1;
        }

        id=*pId;
        auxEmpleado->id=id;
        printf("ID: %4d\n\n",auxEmpleado->id);

        if(!utn_getName("Ingrese el nombre del empleado: ","Error. ",2,129,4,nombre)&&
           !employee_getNombre(auxEmpleado,nombre))
        {
            printf("Error al cargar el nombre.\n");
            return -1;
        }
        strcpy(auxEmpleado->nombre,nombre);

        if(!utn_getUnsignedInt("Ingrese horas trabajadas: ","Error.",1,4,0,1000,4,&horasTrabajadas)&&
           !employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas))
        {
            printf("Error al cargar las horas trabajadas.\n");
            return -1;
        }
        auxEmpleado->horasTrabajadas=horasTrabajadas;

        if(!utn_getUnsignedInt("Ingrese sueldo: ","Error.",1,7,0,1000000,4,&sueldo)&&
           !employee_getHorasTrabajadas(auxEmpleado,&sueldo))
        {
            printf("Error al cargar el sueldo.\n");
            return -1;
        }
        auxEmpleado->sueldo=sueldo;

        printf("\n\n");

        (*pId)++;

        retorno=1;

        ll_add(pArrayListEmployee,auxEmpleado);

    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    //int indice;
    int opcion;
    int id;
    char confirma;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    system("cls");
    printf("        Modificar Empleado\n\n");
    printf("Ingrese id: ");
    scanf("%d",&id);

    if(!(ll_get(pArrayListEmployee,id-1)))
    {
        printf("\nNo existe un empleado con el id: %d\n", id);
    }
    else
    {
        id=id-1;
        printf("\n  ID                Nombre   Horas Trabajadas    Sueldo\n");
        mostrarEmpleado(ll_get(pArrayListEmployee,id));
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {

            printf("        Opciones a modificar:\n\n");
            printf("1- Nombre\n");
            printf("2- Horas Trabajadas\n");
            printf("3- Sueldo\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    if(!utn_getName("Ingrese el nombre del empleado: ","Error. ",2,129,4,nombre))
                    {
                        printf("Error al cargar el nombre.\n");
                        return -1;
                    }
                    employee_setNombre(ll_get(pArrayListEmployee,id),nombre);
                    break;

                case 2:
                    if(!utn_getUnsignedInt("Ingrese horas trabajadas: ","Error.",1,4,0,1000,4,&horasTrabajadas))
                    {
                        printf("Error al cargar las horas trabajadas.\n");
                        return -1;
                    }
                    employee_setHorasTrabajadas(ll_get(pArrayListEmployee,id),horasTrabajadas);
                    break;

                case 3:
                    if(!utn_getUnsignedInt("Ingrese sueldo: ","Error.",1,7,0,1000000,4,&sueldo))
                    {
                        printf("Error al cargar el sueldo.\n");
                        return -1;
                    }
                    employee_setSueldo(ll_get(pArrayListEmployee,id),sueldo);
                    break;

                default:
                    printf("Opcion no valida\n");
                    break;
            }


            retorno=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario\n");
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int idUsuario;
    char confirma;

    system("cls");
    printf("        Baja Empleado\n\n");

    printf("Ingrese id: ");
    scanf("%d",&idUsuario);

    if(!(ll_get(pArrayListEmployee,idUsuario-1)))
    {
        printf("\nNo existe un empleado con el id: %d\n", idUsuario);
    }
    else
    {
        idUsuario=idUsuario-1;

        printf("\n  ID                Nombre   Horas Trabajadas    Sueldo\n");
        mostrarEmpleado(ll_get(pArrayListEmployee,idUsuario));
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            ll_remove(pArrayListEmployee,idUsuario);
            retorno=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    char buffer[4][128];
    FILE* f=fopen("data.csv","r");

    if(f==NULL)
    {
        printf("No se pudo cargar el archivo\n");
    }

    //agrega el encabezado de cada columna para leerlo por consola
    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
    printf("%4s  %20s  %4s      %6s\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    for(int i=0;i<ll_len(pArrayListEmployee);i++)
    {
        mostrarEmpleado(ll_get(pArrayListEmployee,i));
    }

    fclose(f);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int order;
    int opcion;

    system("cls");
    printf("        Campos a ordenar:\n\n");
            printf("1- Id\n");
			printf("2- Nombre\n");
            printf("3- Horas Trabajadas\n");
            printf("4- Sueldo\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    system("cls");
                    if(!utn_getUnsignedInt("\t***   ID   ***\n\n***Orden de la lista a mostrar***"
					"\n\n1- Descendente\n2- Ascendente\n\nIngrese la opcion deseada: ","Error. "
					,1,2,1,2,4,&order))
                    {
                        printf("Error al cargar su los datos\n");
                    }
					else
					{
					    if(order==2)
                        {
                            order=0;
                        }
                        printf("\nEsperando status...\n\n");
						ll_sort(pArrayListEmployee,employee_compareId,order);
						printf("Ordenamiento exitoso!\n\n");
					}
                    break;

                case 2:
                    system("cls");
                    if(!utn_getUnsignedInt("\t***   Nombre   ***\n\n***Orden de la lista a mostrar***"
					"\n\n1- Descendente\n2- Ascendente\n\nIngrese la opcion deseada: ","Error. "
					,1,2,1,2,4,&order))
                    {
                        printf("Error al cargar su los datos\n");
                    }
					else
					{
					    if(order==2)
                        {
                            order=0;
                        }
                        printf("\nEsperando status...\n\n");
						ll_sort(pArrayListEmployee,employee_compareNombre,order);
						printf("Ordenamiento exitoso!\n\n");
					}
                    break;

                case 3:
                    system("cls");
                    if(!utn_getUnsignedInt("\t***   Horas Trabajadas   ***\n\n***Orden de la lista a mostrar***"
					"\n\n1- Descendente\n2- Ascendente\n\nIngrese la opcion deseada: ","Error. "
					,1,2,-1,2,4,&order))
                    {
                        printf("Error al cargar su los datos\n");
                    }
					else
					{
					    if(order==2)
                        {
                            order=0;
                        }
                        printf("\nEsperando status...\n\n");
						ll_sort(pArrayListEmployee,employee_compareHorasTrabajadas,order);
						printf("Ordenamiento exitoso!\n\n");
					}
                    break;
				case 4:
				    system("cls");
                    if(!utn_getUnsignedInt("\t***   Sueldo   ***\n\n***Orden de la lista a mostrar***"
					"\n\n1- Descendente\n2- Ascendente\n\nIngrese la opcion deseada: ","Error. "
					,1,2,1,2,4,&order))
                    {
                        printf("Error al cargar su los datos\n");
                    }
					else
					{
					    if(order==2)
                        {
                            order=0;
                        }
                        printf("\nEsperando status...\n\n");
						ll_sort(pArrayListEmployee,employee_compareSueldo,order);
						printf("Ordenamiento exitoso!\n\n");
					}
                    break;

                default:
                    printf("Opcion no valida\n");
                    break;
            }

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int id;
    int cant;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];

    FILE* f=fopen(path,"w");
    if(f==NULL)
    {
        printf("No se pudo guardar el archivo\n");
    }

    fprintf(f,"ID,Nombre,Horas Trabajadas,Sueldo\n");

    for(int i=0;i<ll_len(pArrayListEmployee);i++)
    {
        if(pArrayListEmployee!=NULL)
        {
            employee_getId(ll_get(pArrayListEmployee,i),&id);
            employee_getNombre(ll_get(pArrayListEmployee,i),nombre);
            employee_getHorasTrabajadas(ll_get(pArrayListEmployee,i),&horasTrabajadas);
            employee_getSueldo(ll_get(pArrayListEmployee,i),&sueldo);

            cant=fprintf(f,"%d,%s,%d,%d\n",
                     id
                    ,nombre
                    ,horasTrabajadas
                    ,sueldo);
            if(cant<4)
            {
                break;
            }
            retorno=1;
        }
    }

    fclose(f);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int cant;
    int retorno=0;

    FILE* f=fopen(path,"wb");

    if(f==NULL)
    {
        printf("No se pudo guardar el archivo\n");
        exit(1);
    }

    for(int i=0;i<ll_len(pArrayListEmployee);i++)
    {
        if(pArrayListEmployee!=NULL)
        {
            cant=fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,f);
            if(cant<1)
            {
                printf("Error\n");
                break;
            }
            retorno=1;
        }
    }

    fclose(f);

    return retorno;
}

