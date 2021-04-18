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

TBinario removerMayor(TBinario b){
    
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
    return b;
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