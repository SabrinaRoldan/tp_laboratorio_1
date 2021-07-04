#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "alumnos.h"

int mostrarAlumno(eAlumno* this)
{
    int retorno=0;

    if(this!=NULL)
    {
      printf("%4d  %10s  %10s    %2d    %c\n"
           ,this->id
           ,this->nombre
           ,this->apellido
           ,this->edad
           ,this->sexo);
        retorno=1;
    }

    return retorno;
}

void mostrarAlumnos(LinkedList* lista)
{
    printf(" Id       Nombre    Apellido  Edad Sexo\n");
    for(int i=0;i<ll_len(lista);i++)
    {
        mostrarAlumno((eAlumno*) ll_get(lista,i));
    }
    printf("\n");
}

int alumnos_compararaNombre(void* alumno1, void* alumno2)
{
    int retorno=0;

    eAlumno* alum1=NULL;
    eAlumno* alum2=NULL;

    if(alumno1!=NULL && alumno2!=NULL)
    {
        alum1=(eAlumno*) alumno1;
        alum2=(eAlumno*) alumno2;

        if(strcmp(alum1->nombre,alum2->nombre)>0)
        {
            retorno=-1;
        }
        else if(strcmp(alum1->nombre,alum2->nombre)<0)
        {
            retorno=1;
        }
    }
    return retorno;
}
