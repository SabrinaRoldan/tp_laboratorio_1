#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "alumnos.h"


int main()
{
    LinkedList* lista=ll_newLinkedList();
    eAlumno a1={1000,"Ariel","Ojeda",15,'f'};
    eAlumno a2={1001,"Sofia","Fernandez",16,'f'};
    eAlumno a3={1002,"Mercedes","Gomez",14,'f'};
    eAlumno a4={1003,"Marcelo","Lopez",17,'m'};
    eAlumno a5={1004,"Hugo","Guinda",15,'m'};

    ll_add(lista,&a1);
    ll_add(lista,&a2);
    ll_add(lista,&a3);
    ll_add(lista,&a4);
    ll_add(lista,&a5);


    if(ll_isEmpty(lista))
    {
        printf("La lista esta vacia.\n\n");
    }
    else
    {
        printf("La lista no esta vacia.\n\n");
    }

    printf("Tamanio de la lista: %d\n",ll_len(lista));
    mostrarAlumnos(lista);

    ll_remove(lista,4);//Remover un alumno de la lista
    printf("Tamanio de la lista luego de remover: %d\n",ll_len(lista));
    printf("Indice del elemento 4: %d\n",ll_indexOf(lista,ll_get(lista,4)));//mostrar que el elento 4 ya no existe
    mostrarAlumnos(lista);

    ll_push(lista,4,&a5);
    printf("Tamanio de la lista luego de agregar: %d\n",ll_len(lista));

    printf("Indice del elemento 4: %d\n\n",ll_indexOf(lista,ll_get(lista,4)));//mostrar que el elento 4 existe nuevamente
    mostrarAlumnos(lista);

    ll_set(lista,4,&a4);
    printf("Cambio de indice del elemento 4 al indice 3:\n");
    printf("Indice del elemento 4: %d\n",ll_indexOf(lista,ll_get(lista,4)));
    mostrarAlumnos(lista);

    //Hago uso de la funcion para clonar la misma lista de alumnos y mostrarla.
    LinkedList* lista2=ll_clone(lista);
    printf("Mostrar lista clonada: \n");
    mostrarAlumnos(lista2);

    //Creo un nuevo alumno para demostrar que no esta dentro de la lista
    eAlumno a6={1005,"Patricia","Ramos",16,'f'};

    if(!ll_contains(lista,&a6))
    {
        printf("El alumno no se encuentra en la lista\n");
    }
    else
    {
        printf("El alumno se encuentra en la lista\n");
    }
    mostrarAlumnos(lista);

    if(ll_containsAll(lista2,lista))
    {
        printf("La lista 1 esta dentro de la lista 2\n\n");
    }
    else
    {
        printf("La lista 1 no esta dentro de la lista 2\n\n");
    }

    //Creo una nueva lista con la funcion de subLista para que solo obtenga los elementos seleccionados.
    LinkedList* lista3=ll_subList(lista,0,3);
    //Solo obtiene los elementos de los indices del 0 al 2 ya que el 3 no esta incluido.
    printf("Contenido de la lista 3: \n");
    mostrarAlumnos(lista3);

    //Ordenamiendo de la lista 1 por nombre
    ll_sort(lista,alumnos_compararaNombre,0);
    printf("Alumnos de la lista 1 luego del ordenamiento: \n");
    mostrarAlumnos(lista);

    //Se elimina el alumno en el indice 0
    ll_pop(lista,0);
    mostrarAlumnos(lista);

    ll_clear(lista);
    ll_clear(lista2);
    ll_clear(lista3);
    printf("Lista 1 luego del clear: \n");
    mostrarAlumnos(lista);

    if(ll_deleteLinkedList(lista)&&
       ll_deleteLinkedList(lista2)&&
       ll_deleteLinkedList(lista3))
    {
        printf("Se han eliminado las listas\n");
    }
    else
    {
        printf("No se han eliminado las listas\n");
    }

    return 0;
}
