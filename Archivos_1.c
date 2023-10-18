#include <stdio.h>
#include <stdlib.h>

//La declaracion del registro se hace de esta forma asi se evita tener que poner siempre struct Producto producto, omitiendo la palabra reservada "struct"
typedef struct {
    int id;
    char nombre[50];
    float precio;
}Producto;

//----------------AGREGAR PRODUCTO-------------
void agregarProducto(FILE *archivo) {
    Producto producto;

    printf("Ingrese el ID del producto: ");
    scanf("%d", &producto.id);

    printf("Ingrese el nombre del producto: ");
    scanf("%s", producto.nombre);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto.precio);

    //Escribo en el archivo el registro que llene
    fwrite(&producto, sizeof(Producto), 1, archivo);
}

//----------------LISTAR PRODUCTOS-------------
void listarProductos(FILE *archivo) {
    Producto producto;
    int i=1; //Contador para la lista de productos
    
    // Me muevo al principio del archivo
    fseek(archivo, 0, SEEK_SET);

    //Impresion cuando el archivo se encuentra vacio
    if (!fread(&producto, sizeof(Producto), 1, archivo))
    {
        printf("\n\tEl archivo se encuentra vacio!\n");
    }else{
        //Impresion cuando el archivo tiene contenido
        rewind(archivo);//Reinicio el cursor del archivo (esto es por el condicional de arriba que deja el cursor en cualquier lado)
        while (fread(&producto, sizeof(Producto), 1, archivo)) {
            printf("\t------- %d* Producto ------\n",i);
            printf("ID: %d\n", producto.id);
            printf("Nombre: %s\n", producto.nombre);
            printf("Precio: %.2f\n\n", producto.precio);
            i++;
        }
    }
    
}

//----------------BUSCAR PRODUCTO-------------
void buscarProducto(FILE *archivo) {
    int id;
    Producto producto;

    printf("Ingrese el ID del producto que desea buscar: ");
    scanf("%d", &id);
    printf("\n");

    while (fread(&producto, sizeof(Producto), 1, archivo)) {
        if (producto.id == id) {
            printf("\t------- %s ------\n",producto.nombre);
            printf("ID: %d\n", producto.id);
            printf("Precio: %.2f\n\n", producto.precio);
            return;
        }
    }

    printf("\tX No se encontro ningun producto con el ID ingresado X\n");
}

//----------------MAIN-------------
int main() {
    FILE *archivo;
    int opcion;

    //Abro el archivo en modo lectura/escritura
    //"ab+" se utiliza para abrir un archivo binario en modo de escritura y lectura, y para agregar nuevos datos al final del archivo si ya existe.
    archivo = fopen("productos.bin", "ab+");
    
    //Errores al abrir el archivo
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    do {

        printf("\n\t---- Menu de opciones: ----\n");
        printf("1. Agregar un nuevo producto.\n");
        printf("2. Listar todos los productos.\n");
        printf("3. Buscar un producto por su ID.\n");
        printf("4. Eliminar Archivo.\n");
        printf("5. Salir.\n");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion) {
            case 1:
                agregarProducto(archivo);
                break;
            case 2:
                listarProductos(archivo);
                break;
            case 3:
                buscarProducto(archivo);
                break;
            case 4:
                fclose(archivo); //Tiene que estar cerrado para poder borrarlo
                remove("productos.bin"); //Borro el archivo y desp se crea denuevo pero vacio
                //Abro denuevo el archivo
                archivo = fopen("productos.bin", "ab+");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    return 1;
                }
                break;
            case 5:
                break;
            default:
                printf("\nOpción inválida.\n");
                break;
        }
    } while (opcion != 5);
    fclose(archivo);

    return 0;
}
