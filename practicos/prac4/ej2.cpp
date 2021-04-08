#include <cstddef>
#include "ej1.cpp"

struct nodoLista {
    uint elem;
    nodoLista * sig;
};
typedef nodoLista * Lista;

Lista concat(Lista a, Lista b) {
    if (a != NULL) {
        Lista aux = new nodoLista;
        aux->elem = a->elem;
        aux->sig = NULL;
        return concat(aux, a->sig);
    } else if (b != NULL) {
        Lista aux = new nodoLista;
        aux->elem = b->elem;
        aux->sig = NULL;
        return concat(aux, b->sig);
    } else
        return NULL;
}

Lista enOrden(AB ar) {
    if (ar == NULL)
        return NULL;
    else {
        Lista aux = new nodoLista;
        aux->elem = ar->elem;
        aux->sig = NULL;
        return concat(concat(enOrden(ar->izq), aux), enOrden(ar->der));
    }     
}

Lista preOrden(AB ar) {
    if (ar == NULL)
        return NULL;
    else {
        Lista aux = new nodoLista;
        aux->elem = ar->elem;
        aux->sig = NULL;
        return concat(aux, concat(preOrden(ar->izq), preOrden(ar->izq)));
    }     
}

Lista posOrden(AB ar) {
    if (ar == NULL)
        return NULL;
    else {
        Lista aux = new nodoLista;
        aux->elem = ar->elem;
        aux->sig = NULL;
        return concat(concat(posOrden(ar->izq), posOrden(ar->der)), aux);
    }     
}

bool esCamino(AB ar, Lista l) {
    if (ar != NULL && l != NULL && ar->elem == l->elem) {
        return esCamino(ar->der, l->sig) || esCamino(ar->izq, l->sig);
    } else if (ar == NULL && l == NULL)
        return true;
    else 
        return false;
}

// Si ar tiene n nodos, como máximo su camino mas largo tiene n nodos
// y como minimo tiene 1+log(n) nodos (base 2)
Lista caminoMasLargo(AB ar) {
    if (ar != NULL) {
        Lista aux = new nodoLista;
        aux->elem = ar->elem;
        aux->sig = NULL;
        AB masAlto = altura(ar->izq) < altura(ar->der) ? ar->der : ar->izq;
        return concat(aux, caminoMasLargo(masAlto));
    } else
        return NULL;
}

// un AB completo perfectamente balanceado de altura h tiene exp(2, h)-1 nodos
bool esCompletoBalanceado(AB ar) {
    if (ar == NULL)
        return true;
    else  if (ar->der == NULL && ar->izq == NULL) 
        return true;
    else if ((ar->der != NULL && ar->izq == NULL) || (ar->der == NULL && ar->izq != NULL))
        return false;
    else 
        return esCompletoBalanceado(ar->izq) && esCompletoBalanceado(ar->der);
}
