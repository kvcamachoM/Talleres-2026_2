#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <stdbool.h>

typedef struct Contenedor {
    int id;                        
    float tara;                     
    float peso_carga;              
    float peso_total;               
    float costo;                    
    struct Contenedor *anterior;    
    struct Contenedor *siguiente;   
} Contenedor;

typedef struct {
    Contenedor *cabeza;             
    Contenedor *cola;               
    int siguiente_id;               
    int cantidad;                   
} ListaContenedores;


void inicializar_lista(ListaContenedores *lista);
void liberar_toda_la_memoria(ListaContenedores *lista);


int insertar_contenedor(ListaContenedores *lista, float tara, float peso_carga, float costo);
Contenedor* buscar_contenedor(const ListaContenedores *lista, int id);
bool actualizar_contenedor(ListaContenedores *lista, int id, float nueva_tara, float nueva_carga, float nuevo_costo);
bool eliminar_contenedor(ListaContenedores *lista, int id);

void mostrar_detalle_contenedor(const Contenedor *c);
void listar_adelante(const ListaContenedores *lista);
void listar_atras(const ListaContenedores *lista);

#endif