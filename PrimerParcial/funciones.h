#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    int codigoProveedor;
    char descripcion[50];
}eProveedores;

typedef struct {
    int codigoProducto;
    char descripcion[50];
    int importe;
    int cantidad;
    int estado;
    int idProveedor;
}eProductos;

/**
 * Inicializa todos los estados en 1(1=libre y 0=ocupado).
 * @param una lita del tipo eProducto
 * @param el tamaño de la lista
 * @return No devuelve nada.
 */
void inicializarEstados(eProductos lista[], int tam);

/**
 * Obtiene el primer indice libre del array. Si no hay indice libre devuelve -1.
 * @param lista el array se pasa como parametro.
 * @param el tamaño de la lista
 * @return el primer indice disponible o un -1 si no hay disponible.
 */
int obtenerEspacioLibre(eProductos lista[],int tam);

/**
 * Recibe la lista y la posicion de la lista donde agregar el nuevo producto. Agrega un producto si no existe el mismo codigo de producto cargado y a la vez esta activo.
 * @param una lista del tipo eProducto
 * @param posicion del arrya libre
 * @param el tamaño de la lista
 * @param lista de proveedores
 * @param el tamaño de la lista
 * @return No retorna nada. Muestra un mensaje confimando el ingreso del producto.
 */
void agregarProducto(eProductos lista[], int pos, int tam,eProveedores proveedores[], int tam2, int codigo);

/**
 * Muestra la lista de proveedores para seleccionar uno y devolver su codigo.
 * @param una lista del tipo eProveedores.
 * @param el tamaño de la lista.
 * @return Devuelve el codigo del proveedor.
 */
 int elegirProveedor(eProveedores proveedores[], int tam2);

 /**
 * Busca un producto por codigo y devuelve la posicion.
 *  @param una lista del tipo eProducto
 * @param el tamaño de la lista
 * @param codigo a buscar
 * @return la posicion del codigo en la lista.
 */
 int buscarProducto(eProductos lista[],int tam,int codigo);

 /**
 * Recibe un producto y la lista de proveedores y muestra los datos de dicho producto y su proveedor.
 *  @param un producto
 * @param la lista de proveedores
 * @param el tamaño de la lista
 * @return No devuelve nada.
 */
 void mostrarProducto(eProductos producto,eProveedores proveedores[],int tam);

/**
 * Pide el codigo del producto a modificar y guarda nuevos valores en descripcion importe y cantidad.
 *  @param una lista del tipo eProducto
 * @param posicion del arrya libre
 * @param el tamaño de la lista
 * @param lista de proveedores
 * @param el tamaño de la lista
 * @return No retorna nada.
 */
 void modificarProducto(eProductos lista[],int tam, eProveedores proveedores[], int tams);

/**
 * Busca un producto por codigo y la borra.
 * @param una lista del tipo eProducto.
 * @param el tamaño de la lista.
 * @return No devuelve nada. Imprime un mensaje de exito o error si no existe el codigo ingresado.
 */
void borrarProducto(eProductos lista[],int tam);



#endif // FUNCIONES_H_INCLUDED
