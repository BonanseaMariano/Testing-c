#include <stdio.h>

//Esta es solo para imprimir el arreglo
void imprimir_arreglo(int arr[],int tamanio){
    for (int i = 0; i < tamanio-1; i++)
    {
        printf("[%d] ",arr[i]);
    }
}

//---------------------------------------------------------------------
void ordenamientoBurbuja(int arr[],int tamanio){
    for (int i = 0; i < tamanio-1; i++)
    {
        for (int j = 0; j < tamanio-i-1; j++)
        {
            if (arr[j]> arr[j+1])
            {
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

//---------------------------------------------------------------------
void ordenamientoSeleccionDirecta(int arr[],int tamanio){
    for (int i = 0; i < tamanio-1; i++)
    {
        int ind_men = i;
        for (int j = i+1; j < tamanio-1; j++)
        {
            if (arr[ind_men]>arr[j])
            {
                int aux = arr[ind_men];
                arr[ind_men]=arr[j];
                arr[j]=aux;
            }
        }
    }
}

//---------------------------------------------------------------------
void ordenamientoPorInsercion(int arr[], int tamanio) {
    for (int i = 1; i < tamanio; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//---------------------------------------------------------------------
int busquedaBinaria(int arr[],int tamanio,int x){
    int izq = 0;
    int der = tamanio-1;
    while (izq <= der)
    {
        int medio = (izq + der)/2;
        if (x==arr[medio])
        {
            printf("\nEl elemento %d se encontro en la posicion: %d\n",x,medio);
            return medio;
        }
        if (x<arr[medio])
        {
            der=medio-1;
        }else{
            izq=medio+1;
        }   
    }
    printf("\nEl elemento %d NO pudo ser encontrado en el arreglo\n",x);
    return -1;
}


//---------------------------- MAIN --------------------------------
int main(){
    int arr[]={2,1,4,3,3};

    printf("Arreglo sin ordenar:\n");
    imprimir_arreglo(arr,6);

    /* printf("\n\nOrdenamiento Burbuja:\n");
    ordenamientoBurbuja(arr,6); */

    /* printf("\n\nOrdenamiento SeleccionDirecta:\n");
    ordenamientoSeleccionDirecta(arr,6); */
    
    printf("\n\nOrdenamiento Insercion:\n");
    ordenamientoPorInsercion(arr,6);
    
    imprimir_arreglo(arr,6);

    int x;
    printf("\nIngrese un numero a buscar: ");
    scanf("%d",&x);
    busquedaBinaria(arr,6,x);

    return 0;
}