#include <stdio.h>
#include "patio.h"

int main() {

    Patio patio;
    Contenedor contenedor;
    Contenedor retirado;

    int opcion;
    char codigo[5];

    inicializarPatio(&patio);

    do {

        printf("\n==============================\n");
        printf("     PUERTO MANAGER\n");
        printf("==============================\n");
        printf("1. Registrar contenedor\n");
        printf("2. Mostrar patio\n");
        printf("3. Buscar contenedor\n");
        printf("4. Retirar contenedor\n");
        printf("5. Salir\n");
        printf("==============================\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:

                if (patioLleno(&patio)) {

                    printf("\nEl patio esta lleno.\n");

                } else {

                    registrarContenedor(&contenedor);

                    if (insertarContenedor(&patio, contenedor)) {
                        printf("\nContenedor registrado correctamente.\n");
                    }
                }

                break;

            case 2:

                mostrarPatio(&patio);

                break;

            case 3:

                printf("\nIngrese codigo a buscar: ");
                scanf("%4s", codigo);

                int posicion = buscarContenedor(&patio, codigo);

                if (posicion == -1) {

                    printf("Contenedor no encontrado.\n");

                } else {

                    printf("Contenedor encontrado en la posicion %d.\n",
                           posicion + 1);

                    mostrarContenedor(&patio.contenedores[posicion]);
                }

                break;

            case 4:

                if (retirarContenedor(&patio, &retirado)) {

                    printf("\nContenedor retirado:\n");
                    mostrarContenedor(&retirado);

                } else {

                    printf("\nEl patio esta vacio.\n");
                }

                break;

            case 5:

                printf("\nPrograma finalizado.\n");

                break;

            default:

                printf("\nOpcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}