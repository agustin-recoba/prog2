/* 5469187 */

#include "../include/iterador.h"
#include "../include/info.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct rep_nodoNat *listaNat;
struct rep_nodoNat {
    nat info;
    listaNat sig;
};

struct _rep_iterador {
    listaNat inicio, fin, actual;
    bool recorre;
};

TIterador crearIterador() {
    return NULL;
}

TIterador agregarAIterador(nat elem, TIterador iter){

    return iter;
}

TIterador reiniciarIterador(TIterador iter){
    return NULL;
}

TIterador avanzarIterador(TIterador iter) {
    return NULL;
}

nat actualEnIterador(TIterador iter) {
    return 1;
}

bool estaDefinidaActual(TIterador iter){
    return false;
}

void liberarIterador(TIterador iter) {

}