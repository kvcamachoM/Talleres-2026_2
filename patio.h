#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define CAPACIDAD_PATIO 5

typedef struct {
    Contenedor contenedores [CAPACIDAD_PATIO];
    int cantidad;
} Patio;

void inicializarPatio (Patio *p);
int patioLleno (const Patio *p);
int patioVacio (const Patio *p);
int insertarContenedor(Patio *p, Contenedor c);
int buscarContenedor (const Patio *p, const char codigo[]);
int retirarContenedor (Patio *p, Contenedor *c);
void mostrarPatio (const Patio *p);

#endif