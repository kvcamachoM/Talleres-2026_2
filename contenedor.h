#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define MAX_CODIGO 5
#define MAX_TIPO 50

typedef struct {
    char codigo[MAX_CODIGO];
    float peso;
    char tipoCarga[MAX_TIPO];
} Contenedor;

void inicializarContenedor (Contenedor *c);
void registrarContenedor (Contenedor *c);
void mostrarContenedor (const Contenedor *c);

#endif