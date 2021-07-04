

#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    int edad;
    char sexo;
}eAlumno;


#endif // ALUMNOS_H_INCLUDED

int mostrarAlumno(eAlumno* this);
void mostrarAlumnos(LinkedList* lista);
int alumnos_compararaNombre(void* alumno1, void* alumno2);
