#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}fechaIngreso;

typedef struct {
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    fechaIngreso fechaIngreso;
}Empleado;

void mostrarEmpleado(Empleado);
Empleado crearEmpleado();
void mostrarEmpleados(Empleado plantel[],int tam);

int main()
{
    Empleado plantel[] = {{1234,"Juan",26000.60,'m',{03,03,1998}},{5678,"Sofia",27000.70,'f',{04,04,1999}},{9,"Diego",28000.80,'m',{05,05,2000}}};

//    empleadoDos = crearEmpleado();

    mostrarEmpleados(plantel,3);

    ordenarEmpleados(plantel,3);

    mostrarEmpleados(plantel,3);

    return 0;
}
void ordenarEmpleados(Empleado plantel[], int tam){
    int criterio;
    Empleado aux;

    printf("\nPor que criterio desea ordenar? ");
    scanf("%d",&criterio);

    switch(criterio){
    case 1:
    //Ordeno por nombre
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(plantel[i].nombre, plantel[j].nombre)>0)
            {
                aux = plantel[i];
                plantel[i] = plantel[j];
                plantel[j] = aux;
            }
        }
    }
    case 2:
    //Ordeno por legajo
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(plantel[i].legajo>plantel[j].legajo)
            {
                aux = plantel[i];
                plantel[i] = plantel[j];
                plantel[j] = aux;
            }
        }
    }
    case 3:
    //Ordeno por sueldo
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(plantel[i].sueldo>plantel[j].sueldo)
            {
                aux = plantel[i];
                plantel[i] = plantel[j];
                plantel[j] = aux;
            }
        }
    }
    case 4:
    //Ordeno primero por sexo y luego legajo
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(plantel[i].sexo>plantel[j].sexo))
            {
                aux = plantel[i];
                plantel[i] = plantel[j];
                plantel[j] = aux;
            }
            else
            {
                if(plantel[i].sexo, plantel[j].sexo)==0)
                {
                    if(plantel[i].legajo>plantel[j].legajo)
                    {
                        aux = plantel[i];
                        plantel[i] = plantel[j];
                        plantel[j] = aux;
                    }
                }
            }
        }
    }
    }
}

void mostrarEmpleados(Empleado plantel[],int tam){
    for(int i=0; i<tam; i++){
        mostrarEmpleado(plantel[i]);
    }
}

void mostrarEmpleado(Empleado emp){
    printf("\nLegajo: %d.\n",emp.legajo);
    printf("Nombre: %s.\n",emp.nombre);
    printf("Sueldo: $%.2f.\n",emp.sueldo);
    printf("Sexo: %c.\n",emp.sexo);
    printf("Fecha de ingreso: %d/%d/%d.\n",emp.fechaIngreso.dia,emp.fechaIngreso.mes,emp.fechaIngreso.anio);
}

Empleado crearEmpleado(){
    Empleado emp;
    printf("Ingrese legajo: ");
    scanf("%d",&emp.legajo);
    fflush(stdin);
    printf("Ingrese nombre: ");
    gets(emp.nombre);
    fflush(stdin);
    printf("Ingrese sueldo: ");
    scanf("%f",&emp.sueldo);
    fflush(stdin);
    printf("Ingrese sexo: ");
    scanf("%c",&emp.sexo);
    fflush(stdin);
    printf("Ingrese fecha de ingreso DD MM AAAA: ");
    scanf("%d %d %d",&emp.fechaIngreso.dia,&emp.fechaIngreso.mes,&emp.fechaIngreso.anio);
    fflush(stdin);

    return emp;
}
