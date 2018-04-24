#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void inicializarEstados(EPersona lista[], int tam){
    for(int i=0; i<tam;i++){
        lista[i].estado=1;
    }
}

int obtenerEspacioLibre(EPersona lista[]){
    int pos=-1;
    for (int i=0; i<20;i++){
            if (lista[i].estado==1){
                pos = i;
                break;
            }
    }
    return pos;
}


int buscarPorDni(EPersona lista[], int dni){
    int pos=-1;
    for (int i=0;i<20;i++){
        if (lista[i].dni==dni){
            pos=i;
            break;
        }
    }
    return pos;
}


void agregarPersona(EPersona lista[], int pos, int tam){
    int dni;
    int esta;
    printf("\nIngresar dni: ");
    scanf("%d",&dni);
    for (int i=0;i<tam;i++){
        if(lista[i].dni == dni && lista[i].estado==0){
            printf("\nYa existe una persona con ese dni.\n");
            esta=0;
            break;
        }else{
            esta=1;
        }
    }
    if(esta==1){
        fflush(stdin);
        printf("\nIngresar nombre: ");
        gets(lista[pos].nombre);
        fflush(stdin);
        printf("\nIngresar edad: ");
        scanf("%d",&lista[pos].edad);
        fflush(stdin);
        lista[pos].estado=0;
        fflush(stdin);
        lista[pos].dni=dni;
        fflush(stdin);

        printf("\nLa persona ha sido ingresada.\n");
    }
    system("pause");
}

void borrarPersona(EPersona lista[],int tam){
    int dniAborrar;
    printf("\nIngresar el dni de la persona a borrar: ");
    scanf("%d",&dniAborrar);

    for(int i=0; i<tam;i++){
        if (lista[i].dni==dniAborrar){
            lista[i].estado=1;
            printf("\nLa persona ha sido borrada.\n");
            break;
        }else{
            printf("\nNo se encontro una persona con el dni ingresado.\n");
        }
    }
    system("pause");
}

void ordenarPorNombre(EPersona lista[],int tam){
    EPersona aux;
    for(int i=0;i<tam;i++){
        for(int j=i+1;j<tam;j++){
            if(strcmp(lista[i].nombre, lista[j].nombre)>0){
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}

void imprimirLista(EPersona lista[],int tam){
    printf("%-15s%-5s%-10s\n\n", "NOMBRE", "EDAD", "DNI");
    for (int i=0;i<tam;i++){
        if(lista[i].estado==0){
            printf("%-15s%-5d%-10d\n", lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }
    system("pause");
}

void mostrarGrafico(EPersona lista[],int tam){
    int menores=0;
    int intermedios=0;
    int mayores=0;

    for(int i=0;i<tam;i++){
            if(lista[i].edad<19){
                menores++;
            }
    }
}
