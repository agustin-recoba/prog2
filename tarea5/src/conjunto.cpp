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

/* Devuelve un TConjunto con los elementos de iter
   pre: iter es creciente estricto */
static TConjunto iterAConjunto(TIterador iter) {
    int n = cantidadEnIterador(iter);
    if (n > 0) {
        iter = reiniciarIterador(iter);
        nat* elems = new nat[n];

        for (int i = 0; i < n; i++) {
            elems[i] = actualEnIterador(iter);
            iter = avanzarIterador(iter);
        }

        TConjunto sal = arregloAConjunto(elems, n);
        delete[] elems;
        return sal;
    } else
        return NULL;    
}

TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2) {
    TIterador it1 = iteradorDeConjunto(c1);
    TIterador it2 = iteradorDeConjunto(c2);
    
    TIterador unionI = enAlguno(it1, it2);
    TConjunto nuevo = iterAConjunto(unionI);
    
    if (it1 != NULL)
        liberarIterador(it1);
    if (it2 != NULL)
        liberarIterador(it2);
    if (unionI != NULL)
        liberarIterador(unionI);

    return nuevo;
}

TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2) {
    TIterador it1 = iteradorDeConjunto(c1);
    TIterador it2 = iteradorDeConjunto(c2);

    TIterador diff = soloEnA(it1, it2);
    TConjunto nuevo = iterAConjunto(diff);

    if (it1 != NULL)
        liberarIterador(it1);
    if (it2 != NULL)
        liberarIterador(it2);
    if (diff != NULL)
        liberarIterador(diff);

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