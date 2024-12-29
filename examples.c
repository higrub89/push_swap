#include "push_swap.h"


// Definición del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Función para insertar un nodo al inicio de la lista
void insertarAlInicio(Nodo** cabeza, int dato) {
    Nodo* nuevo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
    }
}

// Función para mostrar la lista desde el inicio
void mostrarDesdeInicio(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función principal
int main(void) {
    Nodo* lista = NULL;

    // Insertar elementos en la lista
    insertarAlInicio(&lista, 10);
    insertarAlInicio(&lista, 20);
    insertarAlInicio(&lista, 30);

    // Mostrar la lista
    printf("Lista doblemente enlazada:\n");
    mostrarDesdeInicio(lista);

    return 0;
}
