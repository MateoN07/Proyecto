#include <stdio.h>
#include <conio.h>
#include <time.h>

int main() {
    int NUM, i, j, suma, cuentaPerfectos;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    while (NUM <= 0 || NUM > 600000) {
        printf("Error. El numero debe ser positivo y menor o igual a 600000. Ingrese nuevamente: ");
        scanf("%d", &NUM);
    }

    clock_t inicio, fin;
    double tiempo_transcurrido;

    inicio = clock();

    i = 1;
    cuentaPerfectos = 0;

    while (i <= NUM) {
        suma = 0;
        j = 1;

        while (j < i) {
            if (i % j == 0) {
                suma += j;
            }
            j++;
        }

        if (suma == i) {
            printf("Numero perfecto encontrado: %d\n", i);
            cuentaPerfectos++;
        }

        i++;
    }

    fin = clock();
    tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Cantidad de numeros perfectos encontrados: %d\n", cuentaPerfectos);
    printf("Tiempo de ejecucion: %.6f segundos\n", tiempo_transcurrido);

    getch();
    return 0;
}
