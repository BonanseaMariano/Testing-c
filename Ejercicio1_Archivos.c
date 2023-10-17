#include <stdio.h>

const char *NOM_ARCHIVO = "archivoEjemplo.bin";

//Declarar los arreglos de esta forma permite el no tener que poner struct Producto producto desp, sino unicamente Producto producto
typedef struct
{
    int ID;
    char Nombre[30];
    float Precio;
}Producto;

//Funciones
void Escribir_Producto(Producto *producto,FILE *filePointer, int *Id);
void Leer_Producto(Producto *producto,FILE *filePointer);


int main(){
    FILE *filePointer;
    int Id=0;

    Producto producto;    
    for (int i = 0; i < 2; i++)
    {
        Escribir_Producto(&producto,filePointer, &Id);
    }
    
    Leer_Producto(&producto,filePointer);
    
    return 0;
}


void Escribir_Producto(Producto *producto,FILE *filePointer, int *Id){
    // Abre el archivo en modo escritura binaria
    filePointer = fopen(NOM_ARCHIVO, "w+b");    
    //Cargo Id
    producto->ID = *Id;
    //Cargo Nombre del producto
    printf("Ingrese el nombre del producto:\n");
    scanf("%s", producto->Nombre);
    //Cargo Precio del producto
    printf("Ingrese el precio del producto:\n");
    scanf("%f", &producto->Precio);
    //Escribo en el archivo lo que cargue
    fwrite(&producto, sizeof(Producto), 1, filePointer);
    //Cierro el archivo
    fclose(filePointer);
    //Incremento el Id para que tengan distinto cada nuevo producto
    Id++;
}


void Leer_Producto(Producto *producto,FILE *filePointer){
    // Abre el archivo en modo lectura binaria
    filePointer = fopen(NOM_ARCHIVO, "rb");

    // Lee el archivo hasta que feof() devuelva verdadero
    while (!feof(filePointer)) {
        size_t itemsRead = fread(&producto, sizeof(Producto), 1, filePointer);
        if (itemsRead == 1) { // Verifica que se leyó un registro completo
            printf("Id: %d\nNombre: %s\nPrecio: $%f\n ", producto->ID, producto->Nombre, producto->Precio);
        }
    }
    //Cierro el archivo
    fclose(filePointer);
}




/*QUEDA MANEJAR ESTA PARTE DE LOS ERRORES
    if (filePointer == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return 1;
    }
*/