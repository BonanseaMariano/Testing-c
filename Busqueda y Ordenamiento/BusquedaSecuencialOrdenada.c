#include <stdio.h>

busquedaSecuencialOrdenada(int arr[], int n, int x);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

// Función de búsqueda secuencial ordenada
// Devuelve el índice del elemento si se encuentra, de lo contrario devuelve -1
int busquedaSecuencialOrdenada(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        // Si el elemento actual es mayor que x, entonces el elemento no está presente
        if (arr[i] > x) {
        return -1;
    }
    // Si arr[i] es igual a x, devolvemos el índice
    if (arr[i] == x) {
        return i;
    }
    }
    // Si no encontramos el elemento, devolvemos -1
        return -1;
    }