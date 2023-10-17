#include <stdio.h>
#include <math.h>
#define MAX_OPERACIONES 5

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero.\n");
        return 0;
    }
}

float potencia(float a, float b) {
    return pow(a,b);
}

int main() {
    // Declaración de un array de punteros a funciones
    float (*operaciones[MAX_OPERACIONES])(float, float) = {suma, resta, multiplicacion, division, potencia};

    int opcion; 
    float num1, num2;
    
    printf("Ingrese dos números enteros: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Seleccione una operacion:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Potencia\n");
    scanf("%d", &opcion);
    
    if (opcion >= 1 && opcion <= MAX_OPERACIONES) {
        float resultado = operaciones[opcion - 1](num1, num2);
        printf("Resultado: %.1f\n", resultado);
        
        
    } else {
        printf("Opción no válida.\n");
    }

    return 0;
}