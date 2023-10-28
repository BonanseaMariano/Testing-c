#include <stdio.h>

void seleccionDirecta(int arr[], int n);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

void seleccionDirecta(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Asumir que el índice mínimo es el índice actual
        int min_idx = i;
        // Buscar el mínimo elemento en el subarreglo restante
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar el mínimo elemento encontrado con el primer elemento
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}