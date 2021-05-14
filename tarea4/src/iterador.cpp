/* 5469187 */

#include "../include/iterador.h"
#include "../include/info.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct rep_nodoNat *listaNat;
struct rep_nodoNat {
    nat info;
    listaNat prev, sig;
};

struct _rep_iterador {
    listaNat inicio, fin, actual;
    bool recorre;
};

TIterador crearIterador() {
    return NULL;
}

TIterador agregarAIterador(nat elem, TIterador iter){
    if (iter != NULL && iter->recorre) {
        listaNat nuevoNodo = new rep_nodoNat;
        nuevoNodo->info = elem;
        nuevoNodo->sig = NULL;
        nuevoNodo->prev = iter->fin;
        iter->fin->sig = nuevoNodo;
        iter->fin = nuevoNodo;
        iter->actual = nuevoNodo;
    } else if (iter == NULL) {
        listaNat nuevoNodo = new rep_nodoNat;
        nuevoNodo->info = elem;
        nuevoNodo->info = elem;
        nuevoNodo->sig = NULL;
        nuevoNodo->prev = NULL;
        iter = new _rep_iterador;        
        iter->inicio = nuevoNodo;
        iter->fin = nuevoNodo;
        iter->actual = nuevoNodo;
        iter->recorre = true;
    }
    return iter;
}

TIterador reiniciarIterador(TIterador iter){
    if(iter != NULL) {
        iter->recorre = false;
        iter->actual = iter->inicio;
    } 
    return iter;
}

TIterador avanzarIterador(TIterador iter) {
    iter->actual = iter->actual == NULL ? NULL : iter->actual->sig;
    return iter;
}

nat actualEnIterador(TIterador iter) {
    return iter->actual->info;
}

bool estaDefinidaActual(TIterador iter){
    return iter != NULL && iter->actual != NULL;
}

void liberarIterador(TIterador iter) {
    if (iter != NULL) {
        listaNat l = iter->inicio;
        listaNat aux;
        while (l != NULL) {
            aux = l;
            l = l->sig;
            delete aux;
        }
        delete iter;
    }
    
}