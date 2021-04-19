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
        b->elem = copiaInfo(i);
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
// Misma especificacion que mayor
TInfo menor(TBinario b) {
    while(b->izq != NULL)
        b = b->izq;
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

TBinario removerMenor(TBinario b){
    if(b->izq == NULL) {
        TBinario aux = b;
        b = b->der;
        delete aux;
    } else {
        b->izq = removerMayor(b->izq);
    }
    return b;
}

TBinario removerDeBinario(nat elem, TBinario b) {
    return b;
}

void liberarBinario(TBinario b){

}

bool esVacioBinario(TBinario b){
    return true;
}

bool esAvl(TBinario b){
    return true;
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