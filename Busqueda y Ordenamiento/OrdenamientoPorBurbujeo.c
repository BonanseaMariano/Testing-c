#include <stdio.h>

void ordenamientoPorBurbujeo(int arr[], int n);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

void ordenamientoPorBurbujeo(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
            // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    } 
}