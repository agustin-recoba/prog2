/* 5469187 */

#include "../include/pila.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _rep_pila {
    nat * elems;    // arreglo de naturales elems[tamanio]
    int tope;       // entre -1 y tamanio-1 : posicion del ultimo nat definido. =-1 si es vacia
    int tamanio;    // >0 def. en la creacion de la pila
};

TPila crearPila(nat tamanio) {
    TPila nueva = new _rep_pila;
    nueva->tamanio = tamanio;
    nueva->tope = -1;
    nueva->elems = new nat[tamanio];
    return nueva;
}

TPila apilar(nat num, TPila p) {
    if (p->tope < p->tamanio-1) {
        p->tope = p->tope + 1;
        p->elems[p->tope] = num;
    }
    return p;
}

TPila desapilar(TPila p) {
    if (p->tope > -1) {
        p->tope = p->tope - 1;
    }
    return p;
}

void liberarPila(TPila p) {
    delete[] p->elems;
    delete p;
}

bool estaVaciaPila(TPila p) {
    return p->tope == -1;
}

bool estaLlenaPila(TPila p) {
    return p->tope == p->tamanio - 1;
}

nat cima(TPila p) {
    return p->elems[p->tope];
}