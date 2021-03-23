#include <cstddef>
#include <cstdio>

struct  nodo {
    int  elem;
    nodo *sig;
};
struct  cabezal {
    nodo *primero;
    nodo *actual;
};
typedef  cabezal *lista;

lista null() {
    return NULL;
}

void actual(lista &l) {
    l->actual = l->primero;
}

void next(lista &l) {
    l->actual = l->actual->sig == NULL ? l->primero : l->actual->sig;
}

void insert(int x, lista &l) {
    if (l == NULL) {
        l = new cabezal;
        l->actual = new nodo;
        l->primero = l->actual;
        l->actual->elem = x;
        l->actual->sig = NULL;
    } else {
        nodo* nuevo = new nodo;
        nuevo->elem = x;
        nuevo->sig = l->actual->sig;
        l->actual->sig = nuevo;
        l->actual = nuevo;
    }
}

int element (lista l) {
    return l->actual->elem;
}