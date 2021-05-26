/* 5469187 */

#include "../include/conjunto.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _rep_conjunto {

};

TConjunto crearConjunto() {
    return NULL;
}

TConjunto singleton(nat elem) {
    return NULL;
}

TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2) {
    return c1;
}

TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2) {
    return c1;
}

bool perteneceAConjunto(nat elem, TConjunto c) {
    return false;
}

bool estaVacioConjunto(TConjunto c) {
    return false;
}

nat cardinalidad(TConjunto c) {
    return 0;
}

nat minimo(TConjunto c) {
    return 0;
}

nat maximo(TConjunto c) {
    return 0;
}

TConjunto arregloAConjunto(ArregloNats elems, nat n){
    return NULL;
}

TIterador iteradorDeConjunto(TConjunto c) {
    return NULL;
}

void liberarConjunto(TConjunto c) {
    
}