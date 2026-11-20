#include <stdio.h>
#include <stdlib.h>
//declaracion de variables 
typedef struct Contenedor {
    int id;
    float tara;
    float pesoCarga;
    float pesoTotal;
    float costo;
    struct Contenedor *anterior;
    struct Contenedor *siguiente;
} Contenedor;

Contenedor *cabeza = NULL;//puntero al primer contenedor
Contenedor *cola = NULL;//puntero al ultimo contenedor
int siguienteId = 1; //contador
//fin declaracion de variables
void limpiarEntrada(void) {
    int c;//declaracion de variable c 
    while ((c = getchar()) != '\n' && c != EOF) {}
}

float leerFloat(const char *mensaje) {
    float valor;
    int resultado;
    do {//inicio de bucle do while
        printf("%s", mensaje);
        resultado = scanf("%f", &valor);//lectura de un numero flotante
        if (resultado != 1 || valor < 0) {
            printf("Entrada invalida. Ingrese un numero mayor o igual a cero.\n");
            limpiarEntrada();
        }
    } while (resultado != 1 || valor < 0);
    return valor;
}

int leerEntero(const char *mensaje) {
    int valor;
    int resultado;
    do {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        if (resultado != 1) {
            printf("Entrada invalida. Ingrese un numero entero.\n");
            limpiarEntrada();
        }
    } while (resultado != 1);
    return valor;
}
// muestra el contenido 

void mostrarContenedor(const Contenedor *c) {
    printf("\nCodigo: %d\n", c->id);
    printf("Peso vacio (tara): %.2f\n", c->tara);
    printf("Peso de carga:      %.2f\n", c->pesoCarga);
    printf("Peso total:         %.2f\n", c->pesoTotal);
    printf("Costo asociado:     $%.2f\n", c->costo);
}
//mostrar el contenido 

Contenedor *buscarPorId(int id) {
    Contenedor *actual = cabeza;
    while (actual != NULL) {
        if (actual->id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void insertarContenedor(void) {
    Contenedor *nuevo = (Contenedor *)malloc(sizeof(Contenedor));
    if (nuevo == NULL) {
        printf("Error: no hay memoria disponible.\n");
        return;
    }

    nuevo->id = siguienteId++;
    printf("\n--- REGISTRAR CONTENEDOR ---\n");
    nuevo->tara = leerFloat("Ingrese el peso vacio (tara): ");
    nuevo->pesoCarga = leerFloat("Ingrese el peso de carga: ");
    nuevo->pesoTotal = nuevo->tara + nuevo->pesoCarga;
    nuevo->costo = leerFloat("Ingrese el precio o costo asociado: ");

    nuevo->anterior = cola;
    nuevo->siguiente = NULL;

    if (cabeza == NULL) {// Si la lista está vacía
        cabeza = nuevo;// Asignar el nuevo contenedor como cabeza
        cola = nuevo;// Asignar el nuevo contenedor como cola
    } else {// Si la lista no está vacía
        cola->siguiente = nuevo;// Enlazar el nuevo contenedor al final de la lista
        cola = nuevo;// Actualizar la cola para que apunte al nuevo contenedor
    }

    printf("\nContenedor registrado correctamente. Codigo asignado: %d\n", nuevo->id);
    printf("Peso total calculado: %.2f\n", nuevo->pesoTotal);
}


void buscarContenedor(void) {
    int id = leerEntero("\nIngrese el codigo del contenedor que desea buscar: ");
    Contenedor *encontrado = buscarPorId(id);

    if (encontrado == NULL) {
        printf("No existe un contenedor con el codigo %d.\n", id);
    } else {
        printf("\n--- CONTENEDOR ENCONTRADO ---\n");
        mostrarContenedor(encontrado);
    }
}

void actualizarContenedor(void) {
    int id = leerEntero("\nIngrese el codigo del contenedor que desea actualizar: ");
    Contenedor *c = buscarPorId(id);

    if (c == NULL) {
        printf("No existe un contenedor con el codigo %d.\n", id);
        return;
    }

    printf("\nDatos actuales:\n");
    mostrarContenedor(c);

    printf("\nIngrese los nuevos datos:\n");
    c->tara = leerFloat("Nuevo peso vacio (tara): ");
    c->pesoCarga = leerFloat("Nuevo peso de carga: ");
    c->pesoTotal = c->tara + c->pesoCarga;
    c->costo = leerFloat("Nuevo precio o costo asociado: ");

    printf("\nContenedor actualizado correctamente.\n");
    mostrarContenedor(c);
}

void eliminarContenedor(void) {
    int id = leerEntero("\nIngrese el codigo del contenedor que desea eliminar: ");
    Contenedor *c = buscarPorId(id);

    if (c == NULL) {
        printf("No existe un contenedor con el codigo %d.\n", id);
        return;
    }

    if (c->anterior != NULL) {
        c->anterior->siguiente = c->siguiente;
    } else {
        cabeza = c->siguiente;
    }

    if (c->siguiente != NULL) {
        c->siguiente->anterior = c->anterior;
    } else {
        cola = c->anterior;
    }

    free(c);
    printf("Contenedor eliminado y memoria liberada correctamente.\n");
}

void mostrarAdelante(void) {
    Contenedor *actual = cabeza;

    if (actual == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\n--- RECORRIDO HACIA ADELANTE ---\n");
    while (actual != NULL) {
        mostrarContenedor(actual);
        printf("------------------------------\n");
        actual = actual->siguiente;
    }
}

void mostrarAtras(void) {
    Contenedor *actual = cola;

    if (actual == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\n--- RECORRIDO HACIA ATRAS ---\n");
    while (actual != NULL) {
        mostrarContenedor(actual);
        printf("------------------------------\n");
        actual = actual->anterior;
    }
}

void liberarMemoria(void) {
    Contenedor *actual = cabeza;
    while (actual != NULL) {
        Contenedor *temporal = actual;
        actual = actual->siguiente;
        free(temporal);
    }
    cabeza = NULL;
    cola = NULL;
}


int main(void) {
    int opcion;

    do {
        printf("\n========================================\n");
        printf(" SISTEMA DE GESTION DE CONTENEDORES\n");
        printf("========================================\n");
        printf("1. Registrar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Mostrar todos (hacia adelante)\n");
        printf("6. Mostrar todos (hacia atras)\n");
        printf("0. Salir\n");
        printf("========================================\n");

        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                insertarContenedor();
                break;
            case 2:
                buscarContenedor();
                break;
            case 3:
                actualizarContenedor();
                break;
            case 4:
                eliminarContenedor();
                break;
            case 5:
                mostrarAdelante();
                break;
            case 6:
                mostrarAtras();
                break;
            case 0:
                liberarMemoria();
                printf("Programa finalizado. Memoria liberada.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}