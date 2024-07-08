#include <stdio.h>
#include <time.h>

// Función para verificar si un número es perfecto
int esPerfecto(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma == num;
}

// Función para encontrar y almacenar números perfectos en un arreglo
int encontrarNumerosPerfectos(int limite, int* numerosPerfectos) {
    int cantidad = 0;
    for (int i = 1; i <= limite; i++) {
        if (esPerfecto(i)) {
            numerosPerfectos[cantidad] = i;
            cantidad++;
        }
    }
    return cantidad;
}

int main() {
    int NUM;
    float temp;
    clock_t start, end;
    double cpu_time_used;

    printf("Ingrese un número entero positivo (entre 1 y 510,000): ");
    if (scanf("%f", &temp) != 1 || temp <= 0 || temp != (int)temp) {
        printf("Número no válido. Ingrese un entero positivo.\n");
        return 1;
    }
    NUM = (int)temp;

    if (NUM > 510000) {
        printf("Número demasiado grande. Ingrese un número menor o igual a 510,000.\n");
        return 1;
    } else if (NUM == 0) {
        printf("Número no válido. Ingrese un número mayor que 0.\n");
        return 1;
    }

    int numerosPerfectos[NUM]; // Arreglo para almacenar números perfectos

    start = clock(); // Iniciar medición del tiempo

    // Encontrar números perfectos y obtener la cantidad de ellos
    int cantidad = encontrarNumerosPerfectos(NUM, numerosPerfectos);

    end = clock(); // Finalizar medición del tiempo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Imprimir los números perfectos encontrados
    printf("Números perfectos entre 1 y %d: ", NUM);
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", numerosPerfectos[i]);
    }
    printf("\nCantidad de números perfectos: %d\n", cantidad);

    // Imprimir el tiempo de ejecución
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

    return 0;
}
