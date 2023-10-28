#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi es la posición de partición, arr[pi] está en el lugar correcto
        int pi = partition(arr, low, high);
        // Ordenar por separado los elementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función que toma el último elemento como pivote, coloca el pivote en su posición correcta en el arreglo
// ordenado, y coloca todos los menores (menores que el pivote) a la izquierda y todos los mayores a la
// derecha
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivote
    int i = (low - 1); // índice del elemento menor
    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++; // incrementa el índice del elemento menor
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función para intercambiar valores
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}