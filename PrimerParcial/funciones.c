#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void inicializarEstados(eProductos lista[], int tam){
    for(int i=0; i<tam;i++){
        lista[i].estado=1;
    }
}

int obtenerEspacioLibre(eProductos lista[],int tam){
    int pos=-1;
    for (int i=0; i<tam;i++){
            if (lista[i].estado==1){
                pos = i;
                break;
            }
    }
    return pos;
}

int elegirProveedor(eProveedores proveedores[], int tam){
    int opcionElejida;
    printf("\nElija un proveedor:");
    for(int i=0;i<tam;i++){
        printf("\n%s: %d.",proveedores[i].descripcion,proveedores[i].codigoProveedor);
    }
    printf("\nOpcion:");
    fflush(stdin);
    scanf("%d",&opcionElejida);
    return opcionElejida;
}


void agregarProducto(eProductos lista[], int pos, int tam,eProveedores proveedores[], int tam2, int codigo){
    eProductos prod;

    printf("\nIngresar importe: ");
    scanf("%d",&prod.importe);
    printf("\nIngresar cantidad: ");
    scanf("%d",&prod.cantidad);
    fflush(stdin);
    printf("\nIngresar descripcion: ");
    fflush(stdin);
    gets(prod.descripcion);
    prod.idProveedor=elegirProveedor(proveedores,tam2);
    prod.estado=0;
    prod.codigoProducto=codigo;
    lista[pos]=prod;

    printf("\nEl producto ha sido ingresado.\n");

    system("pause");
    return codigo;
}

int buscarProducto(eProductos lista[],int tam,int codigo){
    int pos=-1;
    for(int i=0; i<tam;i++){
        if(lista[i].codigoProducto==codigo && lista[i].estado==0){
            pos=i;
            break;
        }
    }
    return pos;
}

void mostrarProducto(eProductos producto,eProveedores proveedores[],int tam){
    printf("\nCodigo: %d.\n",producto.codigoProducto);
    printf("Descripcion: %s.\n",producto.descripcion);
    printf("Cantidad: %d.\n",producto.cantidad);
    printf("Importe: $%d.\n",producto.importe);
    for(int i=0;i<tam;i++){
        if(producto.idProveedor==proveedores[i].codigoProveedor){
            printf("Proveedor: %s. \n",proveedores[i].descripcion);
            break;
        }
    }
}

void modificarProducto(eProductos lista[],int tam, eProveedores proveedores[], int tams){
    int codigo;
    printf("\nIngrese el codigo: ");
    scanf("%d",&codigo);

    int esta = buscarProducto(lista,tam,codigo);
    if(esta!=-1){
        mostrarProducto(lista[esta],proveedores,tams);
        int auxImporte;
        int auxCantidad;
        char auxDescripcion[50];
        char respuesta;
        printf("\nIngrese el nuevo importe: $");
        fflush(stdin);
        scanf("%d",&auxImporte);
        fflush(stdin);
        printf("\nIngrese la nueva cantidad: ");
        scanf("%d",&auxCantidad);
        fflush(stdin);
        printf("\nIngrese la nueva descripcion: ");
        gets(auxDescripcion);
        printf("\nEsta seguro que desea modificar el producto? (s/n): ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if (respuesta=='s'){
            lista[esta].importe=auxImporte;
            lista[esta].cantidad=auxCantidad;
            strcpy (lista[esta].descripcion,auxDescripcion);
            printf("\nSe realizo la modificacion.");
        }else{
            printf("\nSe cancelo la modificacion.");
        }
    }else {
        printf("\nNo existe dicho legajo.");
    }
    system("pause");
}

void borrarProducto(eProductos lista[],int tam){
    int codigo;
    printf("\nIngresar el codigo del producto a borrar: ");
    scanf("%d",&codigo);

    for(int i=0; i<tam;i++){
        if (lista[i].codigoProducto==codigo){
            lista[i].estado=1;
            printf("\nEl producto ha sido borrado.\n");
            break;
        }else{
            printf("\nNo se encontro un producto con el codigo ingresado.\n");
        }
    }
    system("pause");
}

void mostrarImportes(eProductos lista[],int tam){
    int total=0;
    float promedio=0;
    int cant=0;
    for(int i=0;i<tam;i++){
        total=total+lista.importe;
        if(lista.estado==0){
            cant++;
        }
    }
    promedio=total/cant;
    printf("\nTotal y promedio de los importes:\n");
    printf("\nTotal:%d\n",&total);
    printf("\nPromedio:%.2f\n",&promedio);

}

void mostrarInformes(){
    mostrarImportes();
}
