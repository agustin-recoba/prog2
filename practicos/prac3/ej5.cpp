#include <cstddef>
#include <cstdio>

struct  nodo_doble {
    int  elem;
    nodo_doble *sig;
    nodo_doble *ant;
};

typedef  nodo_doble *lista;
typedef unsigned int nat;

bool isDefined (lista l, nat i) {
    int j = 0;
    while (l != NULL && j <= i) {
        l = l->sig;
        j++;
    }
    return l != NULL;
}

void insert(lista &l1, int x, nat i) {
    int j = 0;
    lista l = l1;
    while (l != NULL && j <= i) {
        l = l->sig;
        j++;
    }
    lista nueva = new nodo_doble;
    nueva->elem = x;
    nueva->sig = l;
    nueva->ant = l->ant;
    l->ant->sig = nueva;
    l->ant = nueva;
}

int element(lista &l1, nat i) {
    int j = 0;
    lista l = l1;
    while (l != NULL && j <= i) {
        l = l->sig;
        j++;
    }
    return l->elem;
}

void remove(lista &l1, nat p) {
    if (isDefined(l1, p)) {
        lista l = l1;
        int j = 0;
        while (l != NULL && j <= p) {
            l = l->sig;
            j++;
        }
        lista aux = l;
        l->ant = l->sig;
        l->sig = aux->ant;
        delete aux;
    }
}

