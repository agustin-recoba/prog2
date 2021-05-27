/* 5469187 */

#include "../include/avl.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


struct _rep_avl {
    nat elem;
    nat altura;
    nat cantNodos;
    TAvl izq, der;
};

TAvl crearAvl() {
    return NULL;
}

bool estaVacioAvl(TAvl avl) {
    return avl == NULL;
}

static nat max(nat a, nat b) { //O(1)
    return a > b ? a : b;
}

static TAvl rotacionIzquierda(TAvl avl) { //O(1)
    TAvl avlDer = avl->der;
    TAvl avlDerIzq = avlDer->izq;

    avlDer->izq = avl;
    avl->der = avlDerIzq;

    avl->cantNodos = cantidadEnAvl(avl->izq) + cantidadEnAvl(avl->der) + 1;
    avlDer->cantNodos = cantidadEnAvl(avlDer->izq) + cantidadEnAvl(avlDer->izq) + 1;

    avl->altura = max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der)) + 1;
    avlDer->altura = max(alturaDeAvl(avlDer->izq), alturaDeAvl(avlDer->der)) + 1;

    return avlDer;
}

static TAvl rotacionDerecha(TAvl avl) { //O(1)

    TAvl y = avl->izq;
    TAvl yD = y->der;

    y->der = avl;
    avl->izq = yD;

    avl->cantNodos = cantidadEnAvl(avl->izq) + cantidadEnAvl(avl->der) + 1;
    y->cantNodos = cantidadEnAvl(y->izq) + cantidadEnAvl(y->der) + 1;

    avl->altura = max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der)) + 1;
    y->altura = max(alturaDeAvl(y->izq), alturaDeAvl(y->der)) + 1;

    return y;
}

// Devuelve la diferencia de altura entre los subarboles izq y der: +=pesoDerecho, -=pesoIzq
static int balanceDerIzq(TAvl avl) { //O(1)
    return avl == NULL? 0 : alturaDeAvl(avl->izq) - alturaDeAvl(avl->der);
} 

TAvl insertarEnAvl(nat elem, TAvl avl) {
    if (avl == NULL) {
        avl = new _rep_avl;
        avl->altura = 1;
        avl->der = avl->izq = NULL;
        avl->elem = elem;
        avl->cantNodos = 1;
        return avl;
    } 
    if (elem < avl->elem)
        avl->izq = insertarEnAvl(elem, avl->izq);
    else
        avl->der = insertarEnAvl(elem, avl->der);
    
    avl->altura = 1 + max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der));
    avl->cantNodos = 1 + avl->cantNodos;

    int balanceo = balanceDerIzq(avl);

    //Cuatro casos de desbalanceo:
    if (balanceo > 1 && elem < avl->izq->elem)
        return rotacionDerecha(avl);
    else if (balanceo > 1 && elem > avl->izq->elem) {
        avl->izq = rotacionIzquierda(avl->izq);
        return rotacionDerecha(avl);
    } else if (balanceo < -1 && elem > avl->der->elem)
        return rotacionIzquierda(avl);
    else if (balanceo < -1 && elem < avl->der->elem) {
        avl->der = rotacionDerecha(avl->der);
        return rotacionIzquierda(avl);
    } else
        return avl;
}

TAvl buscarEnAvl(nat elem, TAvl avl) {
    if (avl == NULL)
        return NULL;
    else if (elem > avl->elem)
        return buscarEnAvl(elem, avl->der);
    else if (elem < avl->elem)
        return buscarEnAvl(elem, avl->izq);
    else
        return avl;
}

nat raizAvl(TAvl avl) {
    return avl->elem;
}

TAvl izqAvl(TAvl avl) {
    return avl->izq;
}

TAvl derAvl(TAvl avl) {
    return avl->der;
}

nat cantidadEnAvl(TAvl avl) {
    return avl == NULL ? 0 : avl->cantNodos;
}

nat alturaDeAvl(TAvl avl) {
    return avl == NULL ? 0 : avl->altura;
}

void enOrdenAvlAUX(TAvl avl, TIterador &iter) {
    if (avl != NULL) {
        enOrdenAvlAUX(avl->izq, iter);
        iter = agregarAIterador(avl->elem, iter);
        enOrdenAvlAUX(avl->der, iter);
    }
}

TIterador enOrdenAvl(TAvl avl) {
    TIterador nuevo = crearIterador();
    enOrdenAvlAUX(avl, nuevo);
    return nuevo;
}

static TAvl arregloAAvlAUX(ArregloNats elems, int indInf, int indSup) {
    if (indSup < indInf)
        return NULL;
    else if (indInf == indSup) {
        TAvl nodo = new _rep_avl;
        nodo->elem = elems[indInf];
        nodo->izq = nodo->der = NULL;
        nodo->altura = 1;
        nodo->cantNodos = 1;
        return nodo;
    } else {
        TAvl nodo = new _rep_avl;
        int medio = (indInf + indSup) / 2;
        nodo->elem = elems[medio];
        nodo->izq = arregloAAvlAUX(elems, indInf, medio - 1);
        nodo->der = arregloAAvlAUX(elems, medio + 1, indSup);
        nodo->altura = 1 + max(alturaDeAvl(nodo->izq), alturaDeAvl(nodo->der));
        nodo->cantNodos = indSup-indInf + 1;
        return nodo;
    }
}

TAvl arregloAAvl(ArregloNats elems, nat n) {
    return arregloAAvlAUX(elems, 0, n-1);
}

TAvl avlMinAUX(int h, nat min) {
    if (h <= 0)
        return NULL;
    else {
        TAvl nuevo = new _rep_avl;
        nuevo->altura = (nat) h;
        
        nuevo->izq = avlMinAUX(h-1, min);
        nuevo->elem = cantidadEnAvl(nuevo->izq) + 1 + min;

        nuevo->der = avlMinAUX(h-2, min + cantidadEnAvl(nuevo->izq) + 1);

        nuevo->cantNodos = cantidadEnAvl(nuevo->izq) + cantidadEnAvl(nuevo->der) + 1;
        return nuevo;
    }
}

TAvl avlMin(nat h) {
    return avlMinAUX((int) h, 0);
}

void liberarAvl(TAvl avl) {
    if (avl != NULL) {
        liberarAvl(avl->izq);
        liberarAvl(avl->der);
        delete avl;
    }    
}