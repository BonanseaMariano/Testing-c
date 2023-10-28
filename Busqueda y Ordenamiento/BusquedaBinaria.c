#include <stdio.h>

int busquedaBinaria(int arr[], int tam, int x);

int main(){
    //Aca se declara el arreglo y se le llama a la funcion pasandole todos los parametros necesarios
}

// Función de búsqueda binaria
// Devuelve el índice del elemento si se encuentra, de lo contrario devuelve -1
int busquedaBinaria(int arr[], int tam, int x) {
    int l=0;
    int r= tam-1;
    while (l <= r) {
        int m = (l + r) / 2;
        // Si el elemento está presente en la mitad misma
        if (arr[m] == x) {
            return m;
        }
        // Si el elemento es mayor, ignorar la mitad izquierda
        if (arr[m] < x) {
            l = m + 1;
        }
        // Si el elemento es menor, ignorar la mitad derecha
        else {
            r = m - 1;
        }
    }
    // Si no encontramos el elemento, devolvemos -1
    return -1;
    }