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
    TBinario nuevo = new _rep_binario;
    nuevo->elem = NULL;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}