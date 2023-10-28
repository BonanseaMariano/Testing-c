#include <stdio.h>

void ordenamientoPorInsercion(int arr[], int n);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

void ordenamientoPorInsercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Mover los elementos del arr[0..i-1] que son mayores que la llave
        // a una posición adelante de su posición actual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}