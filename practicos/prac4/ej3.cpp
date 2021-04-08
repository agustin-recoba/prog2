#include <cstddef>
typedef unsigned int uint;
struct nodoABB {
        uint elem;
        nodoABB * izq, * der;
};
typedef nodoABB * ABB;
struct nodoLista {
    ABB ar;
    nodoLista * sig;
};
typedef nodoLista * ListaABB;

void insertarABB(ABB &ar, uint x) {
    if(ar == NULL) {
        ar = new nodoABB;
        ar->elem = x;
        ar->izq = ar->der = NULL;
    } else if (x < ar->elem)
        insertarABB(ar->izq, x);
    else if (x > ar->elem)
        insertarABB(ar->der, x);
}

bool perteneceABB(ABB ar, uint x) {
    if (ar == NULL) 
        return false;
    else if (x == ar->elem)
        return true;
    else if (x < ar->elem)
        return perteneceABB(ar->izq, x);
    else
        return perteneceABB(ar->der, x);
}

uint maxABB(ABB ar) {
    return ar->der == NULL ? ar->elem : maxABB(ar->der);
}

void removerMaxABB(ABB &ar) {
    if (ar->der == NULL) {
        ABB aux = ar;
        ar = ar->izq;
        delete aux;
    } else
        removerMaxABB(ar->der);
}

ABB izqDerABB(ABB ar, uint x) {
    if (ar == NULL) 
        return NULL;
    else if ((ar->der != NULL && x == ar->der->elem) || ar->izq != NULL && x == ar->izq->elem)
        return ar;
    else if (x < ar->elem)
        return izqDerABB(ar->izq, x);
    else
        return izqDerABB(ar->der, x);
}

void removerABB(ABB &ar, uint x) {

    // ubico al padre del nodo que contiene a x
    ABB aux = izqDerABB(ar, x);

    // me paro en el nodo que contiene a x
    ABB arX = x < aux->elem ? aux->izq : aux->der;

    if (arX->der != NULL && arX->izq != NULL) {
        // copio el máximo del arbol izq de X, lo saco de donde estaba
        // y lo coloco en lugar de x
        uint maxIzq = maxABB(arX->izq);
        removerMaxABB(arX->izq);
        arX->elem = maxIzq;
    } else if (arX->der == NULL) {
        if (x < aux->elem) {
            aux->izq = arX->izq;
            delete arX;
        } else {
            aux->der = arX->izq;
            delete arX;
        }
    } else if (arX->izq == NULL) {
        if (x < aux->elem) {
            aux->izq = arX->der;
            delete arX;
        } else {
            aux->der = arX->der;
            delete arX;
        }
    } else {
        if (x < aux->elem) {
            aux->izq = NULL;
            delete arX;
        } else {
            aux->der = NULL;
            delete arX;
        }
    }
}

ListaABB concat(ListaABB a, ListaABB b) {
    if (a != NULL) {
        ListaABB aux = new nodoLista;
        aux->ar = a->ar;
        aux->sig = NULL;
        return concat(aux, a->sig);
    } else if (b != NULL) {
        ListaABB aux = new nodoLista;
        aux->ar = b->ar;
        aux->sig = NULL;
        return concat(aux, b->sig);
    } else
        return NULL;
}

ListaABB enOrden(ABB ar) {
    if (ar == NULL)
        return NULL;
    else {
        ListaABB aux = new nodoLista;
        aux->ar = ar;
        aux->sig = NULL;
        return concat(concat(enOrden(ar->izq), aux), enOrden(ar->der));
    } 
}

ABB kaesimo (uint k, ABB a) {
    ListaABB lis = enOrden(a);
    uint i = 1;
    while (lis != NULL && k > i) {
        lis = lis->sig;
        i++;
    }
    return lis == NULL ? NULL : lis->ar;
}

