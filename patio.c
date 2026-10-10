#include <stdio.h>
#include <string.h>
#include "patio.h"

void inicializarPatio (Patio *p) {
    p->cantidad = 0;
}

int patioLleno(const Patio *p) {
    return p->cantidad == CAPACIDAD_PATIO;
}

int patioVacio (const Patio *p) {
    return p->cantidad == 0;
}

int insertarContenedor (Patio *p, Contenedor c) {

    if (patioLleno(p)) {
        return 0;
    }

    p->contenedores[p->cantidad] = c;
    p->cantidad++;

    return 1;
}

int buscarContenedor (const Patio *p, const char codigo[]) {

    for (int i = 0; i < p->cantidad; i++) {

        if (strcmp(p->contenedores[i].codigo, codigo) == 0) {
            return i;
        }
    }

    return -1;
}

int retirarContenedor(Patio *p, Contenedor *c) {

    if (patioVacio(p)) {
        return 0;
    }

    *c = p->contenedores [0];

    for (int i = 0; i < p->cantidad - 1; i++) {
        p->contenedores[i] = p->contenedores [i + 1];
    }

    p->cantidad--;

    return 1;
}

void mostrarPatio (const Patio *p) {

    if (patioVacio(p)) {
        printf("\n El patio esta vacio.\n");
        return;
    }

    printf("\n===== CONTENEDORES EN EL PATIO =====\n");

    for (int i = 0; i < p->cantidad; i++) {

        printf("\nContenedor %d\n", i + 1);
        mostrarContenedor(&p->contenedores[i]);
    }
}