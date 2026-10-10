#include <stdio.h>
#include <string.h>
#include "contenedor.h"

void inicializarContenedor(Contenedor *c) {
    strcpy(c->codigo, "");
    c->peso = 0;
    strcpy(c->tipoCarga, "");
}

void registrarContenedor(Contenedor *c) {

    printf("Ingrese codigo del contenedor (4 caracteres): ");
    scanf("%4s", c->codigo);

    printf ("Ingrese peso en toneladas: ");
    scanf ("%f", &c->peso);

    printf ("Ingrese tipo de carga: ");
    scanf(" %49[^\n]", c->tipoCarga);
}

void mostrarContenedor (const Contenedor *c) {

    printf ("Codigo: %s\n", c->codigo);
    printf ("Peso: %.2f toneladas\n", c->peso);
    printf ("Tipo de carga: %s\n", c->tipoCarga);
}
