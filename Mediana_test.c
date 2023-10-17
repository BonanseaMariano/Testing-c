#include <stdio.h>
#define MAX_OPERACIONES 2

float mediana(int arr[], int tam)
{
    float mediana = 0.0;
    if(tam % 2 == 0) {
        mediana = (arr[tam/2-1] + arr[tam/2])/2.0;
    } else {
        mediana = arr[tam/2];
    }
    return mediana;
}

float media(int arr[], int tam)
{
    float media = 0.0;
    for (int i = 0; i < tam; i++)
    {
        media += arr[i];
    }
    return (media*1.0)/tam;
}

int main(){
    int arreglo[10] = {1,3,3,6,7,8,9,9,10,12};
    float (*operaciones[MAX_OPERACIONES])(int[], int) = {mediana, media};
    
    int opcion;
    printf("Seleccione una operacion:\n");
    printf("1. Mediana\n");
    printf("2. Media\n");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= MAX_OPERACIONES) {
        float resultado = operaciones[opcion - 1](arreglo, 10);
        printf("Resultado: %.1f\n", resultado);
        
        if (opcion==1)
        {
            printf("Mediana: %.1f", resultado);
        }else{
            printf("Media: %.1f", resultado);
        }
        
    } else {
        printf("Opción no válida.\n");
    }
    return 0;
}