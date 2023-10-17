#include <stdio.h>

const char *NOM_ARCHIVO = "archivoEjemplo.bin";

void Escribir_Producto(FILE *filePointer, int *Id);

typedef struct
{
    int ID;
    char Nombre[30];
    float Precio;
}Producto;


int main(){
    FILE *filePointer;
    int Id=0;

    Producto producto;    

    Escribir_Producto(filePointer, &Id);
    printf("Carga Terminada\n");

    // Abre el archivo en modo lectura binaria
    filePointer = fopen(NOM_ARCHIVO, "rb");

    if (filePointer == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Lee el archivo hasta que feof() devuelva verdadero
    while (!feof(filePointer)) {
        size_t itemsRead = fread(&producto, sizeof(Producto), 1, filePointer);
        if (itemsRead == 1) { // Verifica que se leyó un registro completo
            printf("Id: %d\nNombre: %s\nPrecio: $%f\n ", producto.ID, producto.Nombre, producto.Precio);
        }
    }
    fclose(filePointer);
    printf("Lectura Terminada\n");
    return 0;
}


void Escribir_Producto(FILE *filePointer, int *Id){
    Producto producto;

    filePointer = fopen(NOM_ARCHIVO, "w+b");    

    producto.ID = *Id;
    printf("Ingrese el nombre del producto:\n");
    scanf("%s", producto.Nombre);
    printf("Ingrese el precio del producto:\n");
    scanf("%f", &producto.Precio);

    printf("\nPrecio:%f\n", producto.Precio);

    fwrite(&producto, sizeof(Producto), 1, filePointer);
    fclose(filePointer);
    Id++;
}