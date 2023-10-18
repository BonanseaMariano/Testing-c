#include <stdio.h>
#include <stdlib.h>

//La declaracion del registro se hace de esta forma asi se evita tener que poner siempre struct Estudiante estudiante, omitiendo la palabra reservada "struct"
typedef struct {
    char nombre[50];
    int matricula;
    float Prom;
}Estudiante;

//----------------AGREGAR Estudiante-------------
void agregarEstudiante(FILE *archivo) {
    Estudiante estudiante;

    printf("Ingrese el nombre del estudiante: ");
    scanf(" %[^\n]s", estudiante.nombre);

    printf("Ingrese la matricula del estudiante: ");
    scanf("%d", &estudiante.matricula);

    printf("Ingrese la calificacion promedio del estudiante: ");
    scanf("%f", &estudiante.Prom);

    //Escribo en el archivo el registro que llene
    fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
}

//----------------LISTAR ESTUDIANTES-------------
void listarEstudiantes(FILE *archivo) {
    Estudiante estudiante;
    int i=1; //Contador para la lista de estudiantes
    
    //Impresion cuando el archivo se encuentra vacio
    if (!fread(&estudiante, sizeof(Estudiante), 1, archivo))
    {
        printf("\n\tEl archivo se encuentra vacio!\n");
    }else{
        //Impresion cuando el archivo tiene contenido
        rewind(archivo);//Reinicio el cursor del archivo (esto es por el condicional de arriba que deja el cursor en cualquier lado)
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
            printf("\t------- %d* Estudiante ------\n",i);
            printf("Martricula: %d\n", estudiante.matricula);
            printf("Nombre: %s\n", estudiante.nombre);
            printf("Prom: %.2f\n\n", estudiante.Prom);
            i++;
        }
    }
    
}

//----------------BUSCAR ESTUDIANTE-------------
void buscarEstudiante(FILE *archivo) {
    int matricula;
    Estudiante estudiante;

    printf("Ingrese la matricula del estudiante que desea buscar: ");
    scanf("%d", &matricula);
    printf("\n");

    while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
        if (estudiante.matricula == matricula) {
            printf("\t------- %s ------\n",estudiante.nombre);
            printf("ID: %d\n", estudiante.matricula);
            printf("Prom: %.2f\n\n", estudiante.Prom);
            agregarEstudiante(archivo);           
            return;
        }
    }

    printf("\tX No se encontro ningun estudiante con la matricula ingresada X\n");
}

//----------------MAIN-------------
int main() {
    FILE *archivo;
    int opcion;

    //Tengo que abrir y cerrar el archivo en cada operacion que hago para que se actualice entre operaciones
    do {
        //Abro el archivo en modo lectura/escritura
        //"ab+" se utiliza para abrir un archivo binario en modo de escritura y lectura, y para agregar nuevos datos al final del archivo si ya existe.
        archivo = fopen("estudiantes.bin", "ab+");
        
        //Errores al abrir el archivo
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return 1;
        }

        printf("\n\t--- Menu de opciones: ----\n");
        printf("1. Agregar un nuevo estudiante.\n");
        printf("2. Listar todos los productos.\n");
        printf("3. Buscar un estudiante por su ID.\n");
        printf("4. Eliminar Archivo.\n");
        printf("5. Salir.\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        //En todos los casos hay que acordarse de cerrar el archivo al final (incluso al salir del programa)
        switch (opcion) {
            case 1:
                agregarEstudiante(archivo);
                fclose(archivo);
                break;
            case 2:
                listarEstudiantes(archivo);
                fclose(archivo);
                break;
            case 3:
                buscarEstudiante(archivo);
                fclose(archivo);
                break;
            case 4:
                fclose(archivo);
                remove("estudiantes.bin"); //Borro el archivo y desp se crea denuevo pero vacio
                break;
            case 5:
                fclose(archivo);
                break;
            default:
                printf("\nOpción inválida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
