#include <cstddef>
#include <cstdio>

struct  nodo_doble {
    int  elem;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef  nodo_doble *lista;

lista null() {
    return NULL;
}

lista cons (int x, lista l) {
    l->ant = new nodo_doble;
    l->ant->sig = l;
    l->ant->elem = x;
    return l->ant;
}

bool isEmpty (lista l) {
    return l == NULL;
}

bool isElement (lista l, int x) {
    while (l != NULL && l->elem != x) {
        l = l->sig;
    }
    return l != NULL;
}

void removeAll (lista &ptr, int x) {
    lista l = ptr;
    while (l != NULL) {
        if (l->elem == x) {
            l->ant->sig = l->sig;
            l->sig->ant = l->ant;
            lista aux = l;
            l = l->sig;
            delete aux;
        } else {
            l = l->sig;
        }
    }
}

void insOrd (lista &l, int x) {
    lista ptr = l;
    while (ptr != NULL && ptr->elem <= x) {
        ptr = ptr->sig;
    }
    lista nueva = new nodo_doble;
    nueva->elem = x;
    nueva->sig = ptr;
    nueva->ant = ptr->ant;
    ptr->ant->sig = nueva;
    ptr->ant = nueva;
}