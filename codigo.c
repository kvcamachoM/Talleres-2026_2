#include <stdio.h>

int calcularFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long factorial(int n) {
    int variableFibonacci = calcularFibonacci(n);
    printf("[INFO] Variable Fibonacci calculada al entrar a factorial(%d): %d\n", n, variableFibonacci);

    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero = 5;

    printf("--- Inicio del programa ---\n");
    long long resultadoFactorial = factorial(numero);
    printf("El factorial de %d es: %lld\n", numero, resultadoFactorial);
    printf("--- Fin del programa ---\n");

    return 0;
}
