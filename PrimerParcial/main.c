#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMPRODUCTOS 10
#define TAMPROVEEDORES 5

int main()
{
    char seguir='s';
    int opcion=0;
    int pos;
    int codigo=1;
    //inicializo los proveedores:
    eProveedores listaProveedores[]= {{1,"proveedor 1"},{2,"proveedor 2"},{3,"proveedor 3"},{4,"proveedor 4"},{5,"proveedor 5"}};

     //Inicializo los estados del array.
    eProductos listaProductos[TAMPRODUCTOS];
    inicializarEstados(listaProductos,TAMPRODUCTOS);

    while(seguir=='s'){
        system("cls");
        printf("\n1- Agregar producto.\n");
        printf("2- Modificar producto.\n");
        printf("3- Borrar un producto\n");
        printf("4- Informar.\n");
        printf("5- Listar.\n\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pos=obtenerEspacioLibre(listaProductos,TAMPRODUCTOS);
                if (pos!=-1){
                    agregarProducto(listaProductos,pos,TAMPRODUCTOS,listaProveedores,TAMPROVEEDORES,codigo);
                    codigo++;
                }else{
                    printf("\nNo hay lugar en la lista. Debe borrar un producto para ingresar otro.\n");
                    system("pause");
                }
                break;
            case 2:
                modificarProducto(listaProductos,TAMPRODUCTOS,listaProveedores,TAMPROVEEDORES);
                break;
            case 3:
                borrarProducto(listaProductos,TAMPRODUCTOS);
                break;
            case 4:
                mostrarInformes();
                system("pause");
                break;
            case 5:

                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
