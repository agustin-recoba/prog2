/* 5469187 */

#include "../include/colaBinarios.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct locArbol {
    TBinario ar;
    locArbol *ant, *sig;
};

struct _rep_colaBinarios {
    locArbol* inicio;
    locArbol* fin;
};

TColaBinarios crearColaBinarios() {
    TColaBinarios nuevaCola = new _rep_colaBinarios;
    nuevaCola->inicio = nuevaCola->fin = NULL;
    return nuevaCola;
}

TColaBinarios encolar(TBinario b, TColaBinarios c) {
    locArbol* nuevo = new locArbol;
    nuevo->ar = b;
    if (c->inicio == NULL) {
        nuevo->sig = nuevo->ant = NULL;
        c->inicio = c->fin = nuevo;
    } else {
        nuevo->ant = c->fin;
        c->fin->sig = nuevo;
        nuevo->sig = NULL;
        c->fin = nuevo;
    }
    return c;
}

TColaBinarios desencolar(TColaBinarios c) {
    if (!estaVaciaColaBinarios(c)) {
        locArbol * aBorrar = c->inicio;
        if (c->fin == c->inicio) {
            c->fin = NULL;
        }
        c->inicio = c->inicio->sig;
        delete aBorrar;
    }
    return c;
}

void liberarColaBinarios(TColaBinarios c) {
    while (c->inicio != NULL)
        c = desencolar(c);
    delete c;
}

bool estaVaciaColaBinarios(TColaBinarios c) {
    return c->inicio == NULL;
}

TBinario frente(TColaBinarios c) {
    return c->inicio->ar;
}