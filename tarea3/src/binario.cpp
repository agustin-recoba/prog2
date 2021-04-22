/* 5469187 */

#include "../include/binario.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _rep_binario {
    TInfo elem;
    TBinario izq, der;
};

TBinario crearBinario() {
    return NULL;
}

TBinario insertarEnBinario(TInfo i, TBinario b) {
    if(b == NULL) {
        b = new _rep_binario;
        b->elem = i;
        b->izq = b->der = NULL;
    } else if (natInfo(i) < natInfo(b->elem))
        b->izq = insertarEnBinario(i, b->izq);
    else if(natInfo(i) > natInfo(b->elem))
        b->der = insertarEnBinario(i, b->der);
    return b;
}

TInfo mayor(TBinario b) {
    while(b->der != NULL)
        b = b->der;
    return b->elem;
}

TBinario removerMayor(TBinario b){
    if(b->der == NULL) {
        TBinario aux = b;
        b = b->izq;
        delete aux;
    } else {
        b->der = removerMayor(b->der);
    }
    return b;
}

TInfo raiz(TBinario b) {
    return b->elem;
}

TBinario izquierdo(TBinario b) {
    return b->izq;
}

TBinario derecho(TBinario b) {
    return b->der;
}

TBinario buscarSubarbol(nat elem, TBinario b) {
    if(b == NULL) {
        return NULL;
    } else if (natInfo(b->elem) == elem) {
        return b;
    } else if (natInfo(b->elem) > elem) {
        return buscarSubarbol(elem, b->izq);
    } else {
        return buscarSubarbol(elem, b->der);
    }
}

static TBinario AUXpadre(nat elem, TBinario b) {
    if (b == NULL)
        return NULL;
    else if ((b->der != NULL && elem == natInfo(b->der->elem)) || b->izq != NULL && elem == natInfo(b->izq->elem))
        return b;
    else if (elem > natInfo(b->elem))
        return AUXpadre(elem, b->der);
    else if (elem < natInfo(b->elem))
        return AUXpadre(elem, b->izq);
}

TBinario removerDeBinario(nat elem, TBinario b) {
    if (natInfo(b->elem) == elem) {
        if ()
    } else {
        // ubico al padre del nodo que contiene a elem
        TBinario padre = AUXpadre(elem, b);

        // me paro en el nodo que contiene a elem
        TBinario arElem = elem < natInfo(padre->elem) ? padre->izq : padre->der;

        if (arElem->der != NULL && arElem->izq != NULL) { //ambas ramas no nulas
            TInfo maxIzq = mayor(arElem->izq);
            arElem->izq = removerMayor(arElem->izq);
            liberarInfo(arElem->elem);
            arElem->elem = maxIzq;
        } else {
            TBinario aux = arElem->der == NULL ? (arElem->izq == NULL ? NULL : arElem->izq) : arElem->der;
            if (natInfo(padre->elem) > elem) {
                liberarInfo(padre->izq->elem);
                delete padre->izq;
                padre->izq = aux;
            } else {
                liberarInfo(padre->der->elem);
                delete padre->der;
                padre->der = aux;
            }
        }
    }
    return b;
}

void liberarBinario(TBinario b){
    if (b != NULL) {
        liberarBinario(b->izq);
        liberarBinario(b->der);
        liberarInfo(b->elem);
        delete b;
    }
}

bool esVacioBinario(TBinario b){
    return b == NULL;
}

bool esAvl(TBinario b){
    return true;
}

nat alturaBinario(TBinario b){
    return 1;
}

nat cantidadBinario(TBinario b) {
    return 2;
}

double sumaUltimosPositivos(nat i, TBinario b){
    return 0.0;
}

TCadena linealizacion(TBinario b) {
    return NULL;
}

TBinario menores(double cota, TBinario b) {
    return b;
}

void imprimirBinario(TBinario b) {

}