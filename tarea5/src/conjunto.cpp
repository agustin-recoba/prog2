/* 5469187 */

#include "../include/conjunto.h"
#include "../include/avl.h"
#include "../include/usoTads.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _rep_conjunto {
    nat min, max;
    TAvl avl;
};

TConjunto crearConjunto() {
    return NULL;
}

TConjunto singleton(nat elem) {
    TConjunto nuevo = new _rep_conjunto;
    nuevo->min = nuevo->max = elem;
    nuevo->avl = insertarEnAvl(elem, NULL);
    return nuevo;
}

TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2) {
    TIterador it1 = iteradorDeConjunto(c1);
    TIterador it2 = iteradorDeConjunto(c2);
    
    TIterador unionI = enAlguno(it1, it2);
    int largoU = cantidadEnIterador(unionI);

    unionI = reiniciarIterador(unionI);
    
    ArregloNats unionC = new nat[largoU];
    for (int i = 0; i <largoU; i++) {
        unionC[i] = actualEnIterador(unionI);
        unionI = avanzarIterador(unionI);
    }

    liberarIterador(it1);
    liberarIterador(it2);
    liberarIterador(unionI);

    TConjunto nuevo = new _rep_conjunto;
    nuevo->avl = arregloAAvl(unionC, largoU);
    nuevo->min = unionC[0];
    nuevo->max = unionC[largoU-1];

    delete[] unionC;

    return nuevo;
}

TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2) {
    TIterador it1 = iteradorDeConjunto(c1);
    TIterador it2 = iteradorDeConjunto(c2);

    it1 = reiniciarIterador(it1);
    it2 = reiniciarIterador(it2);

    if (!estaDefinidaActual(it1)){
        liberarIterador(it1);
        liberarIterador(it2);
        return NULL;
    }
    
    TIterador unionI = soloEnA(it1, it2);
    int largoU = cantidadEnIterador(unionI);

    unionI = reiniciarIterador(unionI);
    
    ArregloNats unionC = new nat[largoU];
    for (int i = 0; i <largoU; i++) {
        unionC[i] = actualEnIterador(unionI);
        unionI = avanzarIterador(unionI);
    }

    liberarIterador(it1);
    liberarIterador(it2);
    liberarIterador(unionI);

    TConjunto nuevo = new _rep_conjunto;
    nuevo->avl = arregloAAvl(unionC, largoU);
    nuevo->min = unionC[0];
    nuevo->max = unionC[largoU-1];

    delete[] unionC;

    return nuevo;
}

bool perteneceAConjunto(nat elem, TConjunto c) {
    if (c != NULL)
        if (c->min <= elem && elem <= c->max)
            return !estaVacioAvl(buscarEnAvl(elem, c->avl));
    return false;
}

bool estaVacioConjunto(TConjunto c) {
    return c == NULL;
}

nat cardinalidad(TConjunto c) {
    return c == NULL ? 0 : cantidadEnAvl(c->avl);
}

nat minimo(TConjunto c) {
    return c->min;
}

nat maximo(TConjunto c) {
    return c->max;
}

TConjunto arregloAConjunto(ArregloNats elems, nat n){
    TConjunto nuevo = new _rep_conjunto;
    nuevo->avl = arregloAAvl(elems, n);
    nuevo->min = elems[0];
    nuevo->max = elems[n-1];
    return nuevo;
}

TIterador iteradorDeConjunto(TConjunto c) {
    TIterador nuevo = enOrdenAvl(c == NULL ? NULL : c->avl);
    return nuevo;
}

void liberarConjunto(TConjunto c) {
    if (c != NULL) {
        liberarAvl(c->avl);
        delete c;
    }
}