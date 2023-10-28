#include <stdio.h>

int busquedaSecuencial(int arr[], int n, int x);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

// Función de búsqueda secuencial
int busquedaSecuencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Retorna el índice del elemento si se encuentra
        }
    }
    return -1; // Retorna -1 si el elemento no está en el array
}